// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// Demonstrates MSVC implementations for
//    Adding the constinit keyword : https://wg21.link/P1143R2 
//    Immediate functions(consteval) : https://wg21.link/P1073R3

#include <iostream>

const char* g() { return "Dynamic initialization"; }
constexpr const char* f(bool isConstantInit) {
	return isConstantInit ? "Constant initializater" : g();
}

// Builds OK
constinit const char* constInitFunc = f(true);

// Fails: illegal initialization of 'constinit' entity with a non-constant expression
//constinit const char* dynamicInitFunc = f(false);

constinit int globalConstInitValue; // Zero initialized

void constinit_demo()
{
	std::cout << "\nconstinit demo:\n";

	std::cout << "constInitFunc: " << constInitFunc << std::endl;
	std::cout << "globalConstInitValue: " << globalConstInitValue << std::endl;

	// Builds OK
	static constinit const char* staticConstInitVal = f(true);
	std::cout << "staticConstInitVal: " << staticConstInitVal << std::endl;

	// Build error:  constinit is only allowed on a variable declaration with static or thread storage duration
	// constinit const char* nonStaticConstInitVal = f(true);

	// This will also fail to build because it's neither static nor thread storage
	// constinit int localConstInit;


	// Builds OK
	constinit static int staticLocalConstInitValue;
	std::cout << "staticLocalConstInitValue: " << staticLocalConstInitValue << std::endl;
}

consteval int myConstEvalFunction(int n) {
	return 10 * n;
}

void consteval_demo()
{
	std::cout << "\nconsteval demo:\n";

	std::cout << myConstEvalFunction(1) << std::endl;

	const int i = 2;
	std::cout << myConstEvalFunction(i) << std::endl;

	// This will return an error if compiled because invoking a consteval function that does not produce a constant expression is ill-formed
	//int j = 3;
	//std::cout << myConstEvalFunction(j) << std::endl;
}

void consteval_and_constinit_demo()
{
	consteval_demo();
	constinit_demo();
}