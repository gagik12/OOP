#include "stdafx.h"
#include "Rectangle.h"
#include "SolidShape.h"
#include "Point.h"
CRectangle::CRectangle(Point const& leftTop, double width, double height, std::string const& outlineColor, std::string const& fillColor)
    :m_leftTop(leftTop),
    m_height(height),
    m_width(width),
    m_fillColor(fillColor),
    m_outlineColor(outlineColor)
{
    m_rightBottom = { leftTop.x + width, leftTop.y + height };
}

double CRectangle::GetWidth() const
{
    return m_width;
};

double CRectangle::GetHeight() const
{
    return m_height;
};


Point const& CRectangle::GetLeftTop() const
{
    return m_leftTop;
}

Point const& CRectangle::GetRightBottom() const
{
    return m_rightBottom;
}

std::string CRectangle::GetOutlineColor() const
{
    return m_outlineColor;
};

std::string CRectangle::GetFillColor() const
{
    return m_fillColor;
};

double CRectangle::GetArea() const
{
    return m_width * m_height;
};

double CRectangle::GetPerimeter() const
{
    return 2 * (m_width + m_height);
};

std::string CRectangle::ToString() const
{
    std::ostringstream strm;
    strm << "Rectangle: "
        << "<" << m_leftTop.x << ", " << m_leftTop.y << ">"
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetOutlineColor()
        << "  FillColor = " << GetFillColor();
    return strm.str();
};

