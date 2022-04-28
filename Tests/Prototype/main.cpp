// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

#include <SA/Serialize/Binary/BinarySerializer.hpp>
using namespace Sa::Ser;

struct A
{
	int i = 0;
	float j = 0.0f;
};

int main()
{
	A src { 5, 3.25f };
	std::string srcStr;

	Serialize::To<Binary>(src, srcStr);

	A dst;
	Reader read(srcStr);
	Serialize::From<Binary>(dst, read);

	LOG("dst.i: " << dst.i);
	LOG("dst.j: " << dst.j);

	return 0;
}
