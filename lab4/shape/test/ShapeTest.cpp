#include "stdafx.h"
#include "../shape/Point.h"
#include "../shape/Circle.h"
#include "../shape/LineSegment.h"
#include "../shape/Triangle.h"
#include "../shape/Rectangle.h"

struct PointFixture_
{
    Point point;
    PointFixture_()
        :point({ 10.2, 23.4 })
    {}
};

BOOST_FIXTURE_TEST_SUITE(PointFixture, PointFixture_)
    BOOST_AUTO_TEST_CASE(can_return_point)
    {
        BOOST_CHECK(point.x == 10.2);
        BOOST_CHECK(point.y == 23.4);
    }
BOOST_AUTO_TEST_SUITE_END()



struct LineFixture_
{
    CLineSegment line;
    LineFixture_()
        :line({ 10, 20 }, { 15, 20 }, "#ff00ff")
    {}
};

BOOST_FIXTURE_TEST_SUITE(LineFixture, LineFixture_)
    BOOST_AUTO_TEST_CASE(line_has_zero_area)
    {
        BOOST_CHECK(line.GetArea() == 0);
    }

    BOOST_AUTO_TEST_CASE(line_has_a_perimeter)
    {
        BOOST_CHECK(line.GetPerimeter() == 5);
    }

    BOOST_AUTO_TEST_CASE(line_get_start_point)
    {
        BOOST_CHECK(line.GetStartPoint().x == 10);
        BOOST_CHECK(line.GetStartPoint().y == 20);
    }

    BOOST_AUTO_TEST_CASE(line_get_end_point)
    {
        BOOST_CHECK(line.GetEndPoint().x == 15);
        BOOST_CHECK(line.GetEndPoint().y == 20);
    }

    BOOST_AUTO_TEST_CASE(line_to_string)
    {
        BOOST_CHECK(line.ToString() == "Line: <10, 20><15, 20>  S = 0  P = 5  ColorOutline = #ff00ff");
    }
BOOST_AUTO_TEST_SUITE_END()



struct CircleFixture_
{
    CCircle circle;
    CircleFixture_()
        :circle({ 10, 20 }, 100, "#ff00ff", "#0000ff")
    {}
};

BOOST_FIXTURE_TEST_SUITE(CircleFixture, CircleFixture_)
    BOOST_AUTO_TEST_CASE(circle_has_a_area)
    {
        BOOST_CHECK(circle.GetArea() == 100 * 100 * M_PI);
    }

    BOOST_AUTO_TEST_CASE(circle_has_a_perimeter)
    {
        BOOST_CHECK(circle.GetPerimeter() == 2 * 100 * M_PI);
    }

    BOOST_AUTO_TEST_CASE(circle_get_center_point)
    {
        BOOST_CHECK(circle.GetCenter().x == 10);
        BOOST_CHECK(circle.GetCenter().y == 20);
    }

    BOOST_AUTO_TEST_CASE(circle_get_radius)
    {
        BOOST_CHECK(circle.GetRadius() == 100);
    }

    BOOST_AUTO_TEST_CASE(circle_get_fill_color)
    {
        BOOST_CHECK(circle.GetFillColor() == "#0000ff");
    }

    BOOST_AUTO_TEST_CASE(circle_get_outline_color)
    {
        BOOST_CHECK(circle.GetOutlineColor() == "#ff00ff");
    }

    BOOST_AUTO_TEST_CASE(circle_to_string)
    {
        BOOST_CHECK(circle.ToString() == "Circle: <10, 20>  R = 100  S = 31415.9  P = 628.319  ColorOutline = #ff00ff  FillColor = #0000ff");
    }
BOOST_AUTO_TEST_SUITE_END()


struct TriangleFixture_
{
    CTriangle triangle;
    TriangleFixture_()
        :triangle({ 0, 0 }, { 0, 3 }, { 4, 3 }, "#ff00ff", "#0000ff")
    {}
};

BOOST_FIXTURE_TEST_SUITE(TriangleFixture, TriangleFixture_)

    BOOST_AUTO_TEST_CASE(triangle_has_a_perimeter)
    {
        BOOST_CHECK(triangle.GetPerimeter() == 12);
    }

    BOOST_AUTO_TEST_CASE(triangle_has_a_area)
    {
        BOOST_CHECK(triangle.GetArea() == 3 * 4 *0.5);
    }


    BOOST_AUTO_TEST_CASE(triangle_get_vertex)
    {
        BOOST_CHECK(triangle.GetVertex1().x == 0);
        BOOST_CHECK(triangle.GetVertex1().y == 0);

        BOOST_CHECK(triangle.GetVertex2().x == 0);
        BOOST_CHECK(triangle.GetVertex2().y == 3);

        BOOST_CHECK(triangle.GetVertex3().x == 4);
        BOOST_CHECK(triangle.GetVertex3().y == 3);
    }

    BOOST_AUTO_TEST_CASE(triangle_get_fill_color)
    {
        BOOST_CHECK(triangle.GetFillColor() == "#0000ff");
    }

    BOOST_AUTO_TEST_CASE(triangle_get_outline_color)
    {
        BOOST_CHECK(triangle.GetOutlineColor() == "#ff00ff");
    }

    BOOST_AUTO_TEST_CASE(triangle_to_string)
    {
        BOOST_CHECK(triangle.ToString() == "Triangle:  S = 6  P = 12  ColorOutline = #ff00ff  FillColor = #0000ff");
    }

BOOST_AUTO_TEST_SUITE_END()


struct RectangleFixture_
{
    CRectangle rectangle;
    RectangleFixture_()
        :rectangle({ 10, 10 }, 100, 10, "#ff00ff", "#0000ff")
    {}
};

BOOST_FIXTURE_TEST_SUITE(RectangleFixture, RectangleFixture_)

    BOOST_AUTO_TEST_CASE(rectangle_has_a_perimeter)
    {
        BOOST_CHECK(rectangle.GetPerimeter() == 220);
    }

    BOOST_AUTO_TEST_CASE(rectangle_has_a_area)
    {
        BOOST_CHECK(rectangle.GetArea() == 1000);
    }


    BOOST_AUTO_TEST_CASE(rectangle_get_vertex)
    {
        BOOST_CHECK(rectangle.GetLeftTop().x == 10);
        BOOST_CHECK(rectangle.GetLeftTop().y == 10);

        BOOST_CHECK(rectangle.GetRightBottom().x == 110);
        BOOST_CHECK(rectangle.GetRightBottom().y == 20);
    }

    BOOST_AUTO_TEST_CASE(rectangle_get_fill_color)
    {
        BOOST_CHECK(rectangle.GetFillColor() == "#0000ff");
    }

    BOOST_AUTO_TEST_CASE(rectangle_get_outline_color)
    {
        BOOST_CHECK(rectangle.GetOutlineColor() == "#ff00ff");
    }

    BOOST_AUTO_TEST_CASE(rectangle_to_string)
    {
        BOOST_CHECK(rectangle.ToString() == "Rectangle: <10, 10>  S = 1000  P = 220  ColorOutline = #ff00ff  FillColor = #0000ff");
    }

BOOST_AUTO_TEST_SUITE_END()