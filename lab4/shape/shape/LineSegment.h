#pragma once
#include "IShape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
    CLineSegment(Point const& startPosition, Point const& endPosition, std::string const& outlineColor);
    ~CLineSegment() = default;
    double GetArea() const override;
    double GetPerimeter() const override;
    std::string GetOutlineColor() const override;

    Point const& GetStartPoint() const;
    Point const& GetEndPoint() const;
protected:
    void AppendProperties(std::ostream & strm) const override;
private:
    Point m_startPoint;
    Point m_endPoint;
    std::string m_outlineColor;
};