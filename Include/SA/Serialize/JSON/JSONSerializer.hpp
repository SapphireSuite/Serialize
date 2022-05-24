// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_JSON_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_JSON_SERIALIZER_GUARD

#include <json.hpp>

namespace SA::Ser
{
//{ ToJSON: Serialize

	template <typename T>
	bool ToJSON(const T& _obj,  nlohmann::json& _json)
	{
		_json = _obj;

		return true;
	}

	template <typename T>
	nlohmann::json ToJSON(const T& _obj)
	{
		nlohmann::json json;

		ToJSON(_obj, json);

		return json;
	}

//}

//{ FromJSON: Deserialize

	template <typename T>
	bool FromJSON(T& _obj, const nlohmann::json& _json)
	{
		_obj = _json.get<T>();

		return true;
	}

//}
}

#endif // GUARD
