module;
#include <print>
#include <string>

export module printing;

import calculating;

export void print_string(std::string_view str, int x);

void print_string(std::string_view str, int x)
{
    std::print("Your string is '{}' = {}\n", str, multiplier(x, x));
}
