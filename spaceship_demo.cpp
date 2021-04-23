// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// Demos MSVC STL implementation of "Adding <=> to the Library" Proposal: https://wg21.link/P1614R2 

#include <iostream>
#include <string>
#include <vector>

void spaceship_in_library_types_demo()
{

    // Set boolalpha format flag so bool values are represented by their textual representation: true or false
    std::boolalpha(std::cout);

    std::cout << "\nOperator <=> in the library demo:\n";

    std::cout << "\nOperator <=> in vector container:\n";

    std::vector<int> a1(3, 10);
    std::vector<int> a2(3, 10);
    std::vector<int> b1(2, 20);

    std::cout << ((a1 <=> a2) == 0) << std::endl; // true
    std::cout << ((a1 <=> b1) < 0) << std::endl; // true
    std::cout << ((b1 <=> a1) == 0) << std::endl; // false

    std::cout << "\nOperator <=> in vector iterator:\n";
    std::cout << ((a1.begin() <=> a1.begin()) == 0) << std::endl; // true
    std::cout << ((a1.begin() <=> a1.end()) < 0) << std::endl; // true
    std::cout << ((b1.begin() <=> b1.end()) == 0) << std::endl;  // false


    std::cout << "\nOperator <=> in string:\n";
    const std::string s1 = "abc";
    const std::string s2 = "abc";
    const std::string s3 = "abcde";
    const std::string s4 = "ab";
    const std::string s5 = "abd";
    const std::string s6 = "abb";

    // All should return true
    std::cout << ((s1 <=> s2) == std::strong_ordering::equivalent) << std::endl;
    std::cout << ((s1 <=> s3) == std::strong_ordering::less) << std::endl;
    std::cout << ((s1 <=> s4) == std::strong_ordering::greater) << std::endl;
    std::cout << ((s1 <=> s5) == std::strong_ordering::less) << std::endl;
    std::cout << ((s1 <=> s6) == std::strong_ordering::greater) << std::endl;

}