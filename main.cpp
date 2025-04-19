#include <chrono>
#include <format>
#include <iostream>
#include <locale>
#include <print>

import printing;
import geometry;

#include "modules/geometry.h"

int main()
{
    std::locale::global(std::locale("ru_RU.UTF8"));
    // std::locale::global(std::locale("en_GB.UTF8"));
    std::cout.imbue(std::locale());
    print_string("I am a man", 4);
    std::print("Localized: {:L%d %B}\n", std::chrono::system_clock::now());
    std::print("C Locale : {:%d %B}\n", std::chrono::system_clock::now());

    const auto point1 = Geometry::Point{.x = 1000, .y = 1500};
    const auto point2 = point1 + Geometry::Point{2, 4};
    const auto rect1 = Geometry::Rect{.left_top = point1, .right_bottom = point2};
    const auto rect2 = rect1 + point1;

    std::println("Localized: point1 = {:L}", point1);
    std::println("C locale : point2 = {}", point2);
    std::println("Localized: rect1 = {:L}", rect1);
    std::println("C locale : rect2 = {}", rect2);
    return 0;
}
