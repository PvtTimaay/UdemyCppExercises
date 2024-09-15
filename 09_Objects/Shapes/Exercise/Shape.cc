#include <cmath>

#include "Shape.hpp"

#include "distance.hpp"
#include "utils.hpp"

double Shape::midpoint_distance(const Shape *other) const
{
}

Circle::Circle(int a, int b, int c)
{
    x_midpoint = a;
    y_midpoint = b;
    radius = c;
}

double Circle::get_area() const
{
}

std::pair<int, int> Circle::get_midpoint() const
{
}
