module;
#include <format>
export module geometry;

namespace Geometry {
export struct Point {
    int x;
    int y;
    friend Point operator+(Point a, Point b);
};

Point operator+(Point a, Point b) {
    return Point{
        .x = a.x + b.x,
        .y = a.y + b.y,
    };
}

export struct Rect {
    Point left_top;
    Point right_bottom;
    friend Rect move(Rect rec, Point vec);
};

Rect move(Rect rec, Point vec) {
    return Rect{
        .left_top = rec.left_top + vec,
        .right_bottom = rec.right_bottom + vec,
    };
}
}// namespace Geometry
