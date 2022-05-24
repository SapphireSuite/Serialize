// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

#include <SA/Collections/Serialize>
using namespace SA;

struct A
{
	int i;
	float j;
};

namespace SA::Ser
{
	template <>
	struct TypeSpecs<A>
	{
		static constexpr bool bContinuousData = true;
	};


	template <>
	bool ToJSON<A>(const A& _obj, nlohmann::json& _json)
	{
		_json['i'] = _obj.i;
		_json['j'] = _obj.j;

		return true;
	}

	template <>
	bool FromJSON<A>(A& _obj, const nlohmann::json& _json)
	{
		_obj.i = _json['i'].get<int>();
		_obj.j = _json['j'].get<float>();

		/** Handle JSON exceptions: return false. */

		return true;
	}

}

int main()
{

	{
		Ser::JSONStream ser;

		const A a1 { 5, 3.24f };
		ser << a1;

		A a2;
		ser >> a2;

		LOG("i: " << a2.i << "\tj: " << a2.j);
	}


	{
		Ser::JSONStream ser;

		const std::string str1 = "hellllo";
		ser << str1;

		std::string str2;
		ser >> str2;


		LOG(str2);
	}


	{
		Ser::JSONStream ser;

		const std::vector<float> v1 = { 4.25f, 3.25f, 2.34f, 1111.2f };
		ser << v1;

		std::vector<float> v2;
		ser >> v2;


		std::string logStr = "{ ";
		
		for(auto& f : v2)
		{
			logStr += std::to_string(f);
			logStr += ", ";
		}

		logStr[logStr.size() - 2] = ' ';
		logStr[logStr.size() - 1] = '}';

		LOG(logStr);
	}


	return 0;
}
