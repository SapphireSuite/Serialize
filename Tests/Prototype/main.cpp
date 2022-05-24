// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

// #include <SA/Collections/Serialize>
// using namespace SA;

#include "TestClass.hpp"

#include "Generated/TestClass.rfks.h"

int main()
{
	LOG("sizeof(TestClass): " << sizeof(TestClass));

	rfk::Class const& c = TestClass::staticGetArchetype();

	LOG(c.getFieldsCount());

	rfk::Visitor<rfk::Field> forFieldLambda = [](const rfk::Field& _field, void* _userData)
	{
		// auto kind = _field.getKind();

		auto type = _field.getType();


		return true;
	};

	c.foreachField(forFieldLambda, nullptr);

	return 0;
}
