#include "stdafx.h"
#include "Control.h"
#include "IShape.h"

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(std::ifstream & input, std::ostream & output)
    :m_input(input)
    , m_output(output)
    , m_actionMap({
        { "line", bind(&CRemoteControl::CreateLine, this, _1) },
        { "circle", bind(&CRemoteControl::CreateCircle, this, _1) },
        { "rectangle", bind(&CRemoteControl::CreateRectangle, this, _1) },
        { "triangle", bind(&CRemoteControl::CreateTriangle, this, _1) },
})
{
}

void CRemoteControl::PrintInfo() const
{
    if (!m_shapes.empty())
    {
        auto shapeWithMinPerimeter = std::min_element(m_shapes.begin(), m_shapes.end(), [&]
        (std::shared_ptr<IShape> const& firstShape, std::shared_ptr<IShape> const& secondShape)
        {
            return firstShape->GetPerimeter() < secondShape->GetPerimeter();
        });
        m_output << "Shape with minimum perimeter:\n";
        m_output << (*shapeWithMinPerimeter)->ToString() << "\n";

        auto shapeWithMaxArea = std::max_element(m_shapes.begin(), m_shapes.end(), [&]
        (std::shared_ptr<IShape> const& firstShape, std::shared_ptr<IShape> const& secondShape)
        {
            return firstShape->GetArea() < secondShape->GetArea();
        });
        m_output << "The shape with the largest area:\n";
        m_output << (*shapeWithMaxArea)->ToString() << "\n";

        m_output << "|SHAPES|\n";
        for (auto const& shape : m_shapes)
        {
            m_output << ">" << shape->ToString() << "\n";

        }
    }
}

bool CRemoteControl::HandleCommand()
{
    string commandLine;
    getline(m_input, commandLine);
    istringstream strm(commandLine);
    string action;
    strm >> action;
    if (strm.eof() && action.empty())
    {
        return true;
    }
    auto it = m_actionMap.find(action);
    if (it != m_actionMap.end())
    {
        it->second(strm);
        return true;
    }
    return false;
}

std::vector<std::string> CRemoteControl::GetTokens(std::string const& shapeSpecification) const
{
    std::vector<std::string> tokens;
    const boost::char_separator<char> delimiters(", ");
    boost::tokenizer<boost::char_separator<char>> tokenizer(shapeSpecification, delimiters);
    std::copy(tokenizer.begin(), tokenizer.end(), std::back_inserter(tokens));
    return tokens;
}

bool CRemoteControl::CreateLine(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 5)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <x2> <y2> <colorOutline>\n";
        return false;
    }
    Point startPoint, endPoint;
    try
    {
        startPoint.x = boost::lexical_cast<double>(tokens[0]);
        startPoint.y = boost::lexical_cast<double>(tokens[1]);
        endPoint.x = boost::lexical_cast<double>(tokens[2]);
        endPoint.y = boost::lexical_cast<double>(tokens[3]);
    }
    catch (boost::bad_lexical_cast const& error)
    {
        m_output << error.what() << "\n";
        return false;
    }
    Color outlineColor;
    if (ConvertHexInRGBColor(tokens[4], outlineColor))
    {
        m_shapes.push_back(std::make_shared<CLineSegment>(CLineSegment(startPoint, endPoint, tokens[4])));
        return true;
    }
    return false;
}

bool CRemoteControl::CreateCircle(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 5)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <radius> <colorOutline> <fillColor>\n";
        return false;
    }
    Point position;
    double radius;
    try
    {
        position.x = boost::lexical_cast<double>(tokens[0]);
        position.y = boost::lexical_cast<double>(tokens[1]);
        radius = boost::lexical_cast<double>(tokens[2]);
    }
    catch (boost::bad_lexical_cast const& error)
    {
        m_output << error.what() << "\n";
        return false;
    }
    Color outlineColor;
    Color fillColor;
    if (ConvertHexInRGBColor(tokens[3], outlineColor) && ConvertHexInRGBColor(tokens[4], fillColor))
    {
        m_shapes.push_back(std::make_shared<CCircle>(CCircle(position, radius, tokens[3], tokens[4])));
        return true;
    }
    return false;
}

bool CRemoteControl::CreateRectangle(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 6)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <width> <height> <colorOutline> <fillColor>\n";
        return false;
    }
    Point position;
    double width;
    double height;
    try
    {
        position.x = boost::lexical_cast<double>(tokens[0]);
        position.y = boost::lexical_cast<double>(tokens[1]);
        width = boost::lexical_cast<double>(tokens[2]);
        height = boost::lexical_cast<double>(tokens[3]);
    }
    catch (boost::bad_lexical_cast const& error)
    {
        m_output << error.what() << "\n";
        return false;
    }

    Color outlineColor;
    Color fillColor;
    if (ConvertHexInRGBColor(tokens[4], outlineColor) && ConvertHexInRGBColor(tokens[5], fillColor))
    {
        m_shapes.push_back(std::make_shared<CRectangle>(CRectangle(position, width, height, tokens[4], tokens[5])));
        return true;
    }
    return false;
}

bool CRemoteControl::CreateTriangle(std::istream & args)
{
    std::string shapeSpecification;
    getline(args, shapeSpecification);
    std::vector<std::string> tokens = GetTokens(shapeSpecification);
    if (tokens.size() != 8)
    {
        m_output << "Invalid number of parameters!!!\n"
            << "Usage: <x1> <y1> <x2> <y2> <x3> <y3> <colorOutline> <fillColor>\n";
        return false;
    }
    Point vertex1;
    Point vertex2;
    Point vertex3;
    try
    {
        vertex1.x = boost::lexical_cast<double>(tokens[0]);
        vertex1.y = boost::lexical_cast<double>(tokens[1]);
        vertex2.x = boost::lexical_cast<double>(tokens[2]);
        vertex2.y = boost::lexical_cast<double>(tokens[3]);
        vertex3.x = boost::lexical_cast<double>(tokens[4]);
        vertex3.y = boost::lexical_cast<double>(tokens[5]);
    }
    catch (boost::bad_lexical_cast const& error)
    {
        m_output << error.what() << "\n";
        return false;
    }
    Color outlineColor;
    Color fillColor;
    if (ConvertHexInRGBColor(tokens[6], outlineColor) && ConvertHexInRGBColor(tokens[7], fillColor))
    {
        m_shapes.push_back(std::make_shared<CTriangle>(CTriangle(vertex1, vertex2, vertex3, tokens[6], tokens[7])));
        return true;
    }
    return false;
}