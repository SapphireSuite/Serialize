// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

#include <SA/Collections/Serialize>
using namespace Sa::Ser;

struct A
{
	int i = 0;
	float j = 0.0f;
};

namespace Sa::Ser
{
	template<>
	struct TypeSpecs<A>
	{
		static constexpr bool bContinuousData = true;
	};
}

int main()
{
	LOG("Single");
	{
		A src { 5, 3.25f };
		std::string srcStr;

		To<Binary>(src, srcStr);

		A dst;
		Reader read(srcStr);
		From<Binary>(dst, read);

		LOG("{ " << dst.i << ", " << dst.j << " }");
	}


	LOG("vector");
	{
		std::vector<A> v1 = { { 6, 4.25f }, { 7, 10.2f } };

		std::string vSrcStr;
		To<Binary>(v1, vSrcStr);

		std::vector<A> v2;
		Reader vRead(vSrcStr);
		From<Binary>(v2, vRead);

		for(auto it = v2.begin(); it != v2.end(); ++it)
			LOG("{ " << it->i << ", " << it->j << " }");
	}

	return 0;
}
