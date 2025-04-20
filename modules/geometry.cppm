module;
export module geometry;

namespace Geometry {
export struct Point {
    int x;
    int y;
    friend constexpr Point operator+(const Point &a, const Point &b);
};

export  constexpr Point operator+(const Point &a, const Point &b)
{
    return Point{
        .x = a.x + b.x,
        .y = a.y + b.y,
    };
}

export struct Rect {
    Point left_top;
    Point right_bottom;
    friend constexpr Rect operator+(const Rect &rec, const Point &vec);
};

export constexpr Rect operator+(const Rect &rec, const Point &vec)
{
    return Rect{
        .left_top = rec.left_top + vec,
        .right_bottom = rec.right_bottom + vec,
    };
}
}// namespace Geometry
