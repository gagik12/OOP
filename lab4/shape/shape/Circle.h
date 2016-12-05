#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
    CCircle(Point const& center, double radius, std::string const& outlineColor, std::string const& fillColor);
    ~CCircle() = default;
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string GetOutlineColor() const override;
    std::string GetFillColor() const override;
    double GetRadius() const;
    Point const& GetCenter() const;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    Point m_center;
    double m_radius;
    std::string m_outlineColor;
    std::string m_fillColor;
};