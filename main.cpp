#include <print>
#include <format>
#include <locale>
#include <iostream>
#include <chrono>

import printing;
import geometry;

#include "modules/geometry.h"

int main() {
    std::locale::global(std::locale("ru_RU.UTF8"));
    std::cout.imbue(std::locale());
    print_string("I am a man", 4);
    std::cout << std::format("{:L%d %B}\n", std::chrono::system_clock::now());

    const auto point1 = Geometry::Point{.x = 1000, .y = 1500};
    const auto point2 = point1 + Geometry::Point{2, 4};
    const auto rect = Geometry::Rect{.left_top = point1, .right_bottom = point2};

    std::print("point1 = {:L}, point2 = {}\n", point1, point2);
    std::print("rect = {}\n", rect);
    std::cout << std::format("rect = {}\n", rect);
    return 0;
}
