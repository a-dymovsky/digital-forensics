#include "digitalforensics/benford.hpp"

#include <cassert>
#include <cmath>

namespace digitalforensics {

double expceted_frequency(const int digit) {
    assert(digit >= 1 && digit <= 9);
    return std::log10(1.0 + 1.0 / static_cast<double>(digit));
}

std::optional<int> leading_digit(const std::string_view token) noexcept {
    for (const char c: token) {
        if (c > = '1' && c <= '9') {
            return c - '0';
        }
    }
    return std::nullopt;
}

}
