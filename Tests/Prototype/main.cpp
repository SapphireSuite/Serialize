// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

// #include <SA/Collections/Serialize>
// using namespace SA;

#include "TestClass.hpp"

int main()
{
	LOG("sizeof(TestClass): " << sizeof(TestClass));

	return 0;
}
