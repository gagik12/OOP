#pragma once
#include "Point.h"
#include "SolidShape.h"

class CTriangle : public ISolidShape
{
public:
    CTriangle(Point const& firstVertex, Point const& secondVertex, Point const& thirdVertex, std::string const& colorOutlines, std::string const& fillColor);

    double GetArea() const override;
    double GetPerimeter() const override;
    double GetSideLength(Point const& firstVertex, Point const& secondVertex) const;
    std::string ToString() const override;
    std::string GetOutlineColor() const override;

    std::string GetFillColor() const override;

    Point const& GetVertex1() const;
    Point const& GetVertex2() const;
    Point const& GetVertex3() const;
private:
    Vertices m_vertices;
    std::string m_outlineColor;
    std::string m_fillColor;
};