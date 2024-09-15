#include <cmath>

#include "Shape.hpp"

#include "distance.hpp"
#include "utils.hpp"

double Shape::midpoint_distance(const Shape *other) const
{
    return get_distance(int a, int b, int c, int d);
}

Circle::Circle(int a, int b, int c)
{
    x_midpoint = a;
    y_midpoint = b;
    radius = c;
}
