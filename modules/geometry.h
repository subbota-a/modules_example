#pragma once

#include <format>

template<>
struct std::formatter<Geometry::Point> {
    std::string format_;
    constexpr auto parse(std::format_parse_context &ctx) {
        std::string format_one;
        auto it = ctx.begin();
        for (; it != ctx.end() && *it != '}'; ++it) {
            format_one.push_back(*it);
        }
        format_ = "({:" + format_one + "}, {:" + format_one + "})";
        return it;
    }

    template<typename FmtCtx>
    typename FmtCtx::iterator format(const Geometry::Point &obj, FmtCtx &ctx) const {
        return std::vformat_to(ctx.out(), ctx.locale(), format_, std::make_format_args(obj.x, obj.y));
    }
};

template<>
struct std::formatter<Geometry::Rect> {
    std::string format_;
    constexpr auto parse(std::format_parse_context &ctx) {
        std::string format_one;
        auto it = ctx.begin();
        for (; it != ctx.end() && *it != '}'; ++it) {
            format_one.push_back(*it);
        }
        format_ = "[{:" + format_one + "}, {:" + format_one + "}]";
        return it;
    }

    template<typename FmtCtx>
    typename FmtCtx::iterator format(const Geometry::Rect &obj, FmtCtx &ctx) const {
        return std::vformat_to(ctx.out(), ctx.locale(), format_, std::make_format_args(obj.left_top, obj.right_bottom));
    }
};
