#include "stdafx.h"
#include "LineSegment.h"
#include "Point.h"

CLineSegment::CLineSegment(Point const& startPoint, Point const& endPoint, std::string const& outlineColor)
    :m_startPoint(startPoint),
    m_endPoint(endPoint),
    m_outlineColor(outlineColor)
{
}

double CLineSegment::GetArea() const
{
    return 0;
};

std::string CLineSegment::GetOutlineColor() const
{
    return m_outlineColor;
};

Point const& CLineSegment::GetStartPoint() const
{
    return m_startPoint;
}

Point const& CLineSegment::GetEndPoint() const
{
    return m_endPoint;
}

double CLineSegment::GetPerimeter() const
{
    double dx = m_startPoint.x - m_endPoint.x;
    double dy = m_startPoint.y - m_endPoint.y;
    return std::hypot(dx, dy);
};

std::string CLineSegment::ToString() const
{
    std::ostringstream strm;
    strm << "Line: "
        << "<" << m_startPoint.x << ", " << m_startPoint.y << ">"
        << "<" << m_endPoint.x << ", " << m_endPoint.y << ">"
        << "  S = " << GetArea()
        << "  P = " << GetPerimeter()
        << "  ColorOutline = " << GetOutlineColor();
    return strm.str();
};

