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
		Ser::BinaryStream serBIN;
		Ser::JSONStream serJSON;

		const A a0 { 5, 3.24f };
		serBIN << a0;
		serJSON << a0;

		A aBIN;
		serBIN >> aBIN;
		LOG("BIN:\ti: " << aBIN.i << "\tj: " << aBIN.j);

		A aJSON;
		serJSON >> aJSON;
		LOG("JSON:\ti: " << aJSON.i << "\tj: " << aJSON.j);
	}


	{
		Ser::BinaryStream serBIN;
		Ser::JSONStream serJSON;

		const std::string str0 = "hellllo";
		serBIN << str0;
		serJSON << str0;

		std::string strBIN;
		serBIN >> strBIN;
		LOG("BIN:\t" << strBIN);

		std::string strJSON;
		serJSON >> strJSON;
		LOG("JSON:\t" << strJSON);
	}


	{
		Ser::BinaryStream serBIN;
		Ser::JSONStream serJSON;

		const std::vector<float> v0 = { 4.25f, 3.25f, 2.34f, 1111.2f };
		serBIN << v0;
		serJSON << v0;

		std::vector<float> vBIN;
		serBIN >> vBIN;
		
		std::vector<float> vJSON;
		serJSON >> vJSON;

		auto print = [](const std::vector<float>& _v, std::string _name){
			std::string logStr = _name + ":\t{ ";
			
			for(auto& f : _v)
			{
				logStr += std::to_string(f);
				logStr += ", ";
			}

			logStr[logStr.size() - 2] = ' ';
			logStr[logStr.size() - 1] = '}';

			LOG(logStr);
		};

		print(vBIN , "BIN");
		print(vJSON , "JSON");
	}


	return 0;
}
