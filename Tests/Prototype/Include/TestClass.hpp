// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_TEST_CLASS_GUARD
#define SAPPHIRE_SERIALIZE_TEST_CLASS_GUARD

#include "Generated/TestClass.rfkh.h"

class CLASS() TestClass
{
public:

	FIELD()
	std::string str;
	
	FIELD()
	int i = 0;
	
	FIELD()
	float j = 0.0f;

	TestClass_GENERATED
};

File_TestClass_GENERATED

#endif // GUARD