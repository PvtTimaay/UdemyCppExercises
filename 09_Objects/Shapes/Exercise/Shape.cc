#include <cmath>

#include "Shape.hpp"

#include "distance.hpp"
#include "utils.hpp"

double Shape::midpoint_distance(const Shape *other) const
{
    const auto [x_midpoint1, y_midpoint1] = this->get_midpoint();
    const auto [x_midpoint2, y_midpoint2] = other->get_midpoint();

    const auto distance = get_distance(x_midpoint1, y_midpoint1, x_midpoint2, y_midpoint2);

    return distance;
}

Circle::Circle(int a, int b, int c) //Konstruktor
{
    x_midpoint = a;
    y_midpoint = b;
    radius = c;
}

Rectangle::Rectangle(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d){} //Konstruktor

double Circle::get_area() const
{
    return pi * std::pow(radius, 2);
}

std::pair<int, int> Circle::get_midpoint() const
{
    return {x_midpoint, y_midpoint};
}

double Rectangle::get_area() const
{
    const auto length_a = std::abs(static_cast<double>(x1) - static_cast<double>(x2));
    const auto length_b = std::abs(static_cast<double>(y1) - static_cast<double>(y2));

    return length_a * length_b;
}

std::pair<int, int> Rectangle::get_midpoint() const
{
    const auto x_midpoint = (x1 + x2) / 2U;
    const auto y_midpoint = (y1 + y2) / 2U;

    return {x_midpoint, y_midpoint};
}
