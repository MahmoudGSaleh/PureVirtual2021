// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// C++20 demos
void ranges_demo();
void spaceship_in_library_types_demo();
void consteval_and_constinit_demo();
void standard_library_header_units_demo();

int main()
{
	//// 1. <ranges>
	//ranges_demo();

	//// 2. Demo for <=> usage in the standard Library
	//spaceship_in_library_types_demo();

	// 3. consteval and constinit demos
	consteval_and_constinit_demo();

	//// 4. Standard Library Header Units Demo
	//standard_library_header_units_demo();
}
