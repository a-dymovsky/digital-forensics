#pragma once

#include <optional>
#include <string_view>

namespace digitalforensics {
    [[nodiscard]] double expected_frequency(int digit);
    [[nodiscard]] std:optional<int> leading_digit(std::string_view token) noexcept;
}
