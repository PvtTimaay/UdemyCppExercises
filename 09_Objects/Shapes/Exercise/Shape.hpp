#pragma once

struct Shape
{
    Shape() = default;
    ~Shape() noexcept = default;

    virtual double get_area() const = 0;
    double midpoint_distance(const Shape *other) const;
    virtual std::pair<int, int> get_midpoint() const = 0;
};

struct Circle : Shape
{
    Circle() = default;
    Circle(int a, int b, int c);
    ~Circle() noexcept = default;

    virtual double get_area() const final;
    virtual std::pair <int, int> get_midpoint() const final;

    int x_midpoint;
    int y_midpoint;
    int radius;
};

struct Rectangle : Shape
{
    Rectangle() = default;
    Rectangle(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d){}
    ~Rectangle() noexcept = default;

    virtual double get_area() const final;
    virtual std::pair <int, int> get_midpoint() const final;

    int x1;
    int y1;
    int x2;
    int y2;
};
