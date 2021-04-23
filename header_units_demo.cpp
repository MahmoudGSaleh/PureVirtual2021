// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// Demo MSVC implementation of Standard library header units for C++20: https://wg21.link/P1502R1

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Replace with header units
//import <algorithm>;
//import <iostream>;
//import <string>;
//import <vector>;


void standard_library_header_units_demo()
{
	std::cout << "\nStandard library header units demo:\n";

	// Some random code to use the types from headers
	std::string hello("Hello C++20");
	std::cout << hello << std::endl;

	std::vector<int> vec = { 1, 2, 3, 4 };

	int sum = 0;
	std::for_each(vec.cbegin(), vec.cend(), [&sum](const int& n) 
		{ 
			sum += n;
		});
	std::cout << "Sum: " << sum << std::endl;

}