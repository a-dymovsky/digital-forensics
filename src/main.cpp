#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include "digitalforensics/benford.hpp"

namespace {

constexpr std::string_view kVersion = "0.1.0";

void print_reference_distribution() {
	std::cout << "reference distribution P(d) = log10(1 + 1/d)\n\n";
	std::cout << std::fixed << std:setprecision(1);
	for (int d = 1; d <=9; ++d) {
		const double pct = digitalforensics::expected_frequency(d) * 100.0;
		const auto bar = static_cast<std::string::size_type>(std::lround(pct));
		std::cout << " " << d << " " << std:setw(4) << pct << "%" << std::string(bar, '#') << '\n';
	}
}
}

int main(const int argc, const char* const argv[]) {
	if (argc > 1) {
		const std::string_view arg{argv[1]};
		if (arg == "--version" || arg == "-v") {
			std::cout << "digitalforensics " << kVersion << '\n';
		}
	std::cout << "Reference distribution prior to data ingestion: \n\n";
	}
	print_reference_distribution();
}
