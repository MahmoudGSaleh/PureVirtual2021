// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// Demos MSVC STL implementation of The One Ranges Proposal: https://wg21.link/P0896R4

#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <string_view>
#include <utility>
#include <vector>

using namespace std::literals;

template<typename T, typename R>
constexpr void print_range(const char* message, const T& list, const R& result)
{
	std::cout << message << " [ ";
	for (auto iter = list; iter != result.out; ++iter)
	{
		std::cout << *iter << ", ";
	}
	std::cout << " ]" << std::endl;
}

constexpr auto get_first = [](auto&& x) -> auto&& {
	return static_cast<decltype(x)>(x).first;
};

constexpr auto get_second = [](auto&& x) -> auto&& {
	return static_cast<decltype(x)>(x).second;
};

template<typename T>
void print_pairs(const char* message, const T& pairs)
{
	std::cout << message << " [ ";
	for (auto const& pair : pairs)
	{
		std::cout << "[" << pair.first << ", " << pair.second << "], ";
	}
	std::cout << " ]" << std::endl;
}

void ranges_copy_demo()
{
	std::cout << "\nstd::ranges::copy() demo\n";

	int const input[] = { 1, 2, 3, 5, 8, 13, 21, 34, 45, 79 };
	int output[10] = { 0 };

	auto range1 = std::ranges::copy(input, output);
	print_range("copy output", output, range1);

	// only copy numbers divisible by 3
	auto range2 = std::ranges::copy_if(input, output, [](const int i) {
		return i % 3 == 0;
		});
	print_range("copy_if %3 output", output, range2);
}

void ranges_find_demo()
{
	std::cout << "\nstd::ranges::find() demo\n";

	std::array<std::pair<int, int>, 3> pairs = { {{17, 10}, {23, 13}, {0, 23}} };
	print_pairs("\nPairs", pairs);
	
	auto result = std::ranges::find(pairs, 73, get_first);
	if (result != std::end(pairs))
	{
		std::cout << "Found {73, *} : " << "{ " << result->first << ", " << result->second << " }" << std::endl;
	}
	else
	{
		std::cout << "{73, *} Not found!" << std::endl;
	}
	
	result = std::ranges::find(pairs, 23, get_second);
	if (result != std::end(pairs))
	{
		std::cout << "Found {*, 23} : " << "{ " << result->first << ", " << result->second << " }" << std::endl;
	}
	else
	{
		std::cout << "{*, 23} Not found!" << std::endl;
	}
}


void ranges_algorithms_demo()
{
	ranges_copy_demo();
	ranges_find_demo();
}

void ranges_views_adapters_demo()
{
	// Examples based on https://en.cppreference.com/w/cpp/ranges
	
	std::cout << "\nstd::ranges::views::counted() demo\n";

	// A counted view presents a view of the elements of the counted range [i, n) for some iterator i and non-negative integer n.
	const auto list = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i : std::ranges::views::counted(list.begin() + 2, 5))
		std::cout << i << ' ';
	
	std::cout << std::endl;
	
	std::cout << "\nstd::ranges::views::split() demo\n";

	// split view takes a view and a delimiter, and splits the view into subranges on the delimiter
	constexpr std::string_view demo_string { "This is a demo of C++20 Ranges"};
	std::ranges::for_each(demo_string | std::ranges::views::split(' '), [](auto const& view) {
		for (std::cout << "["; const auto element : view)
			std::cout << element;
		std::cout << "] ";
		});

	std::cout << std::endl;

	std::cout << "\nstd::ranges::views::join() demo\n";
	const auto url_parts = { "https"sv, "://"sv, "www.mywebsite.com"sv, "/"sv, "index.html"sv };
	for (char const part : url_parts | std::ranges::views::join)
	{
		std::cout << part;
	}

	std::cout << std::endl;
}

void ranges_demo()
{
	std::cout << "\nstd::ranges demos:\n";

	ranges_algorithms_demo();
	ranges_views_adapters_demo();
}
