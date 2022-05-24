// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_JSON_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_JSON_SERIALIZER_GUARD

#include <json.hpp>

namespace SA::Ser
{
//{ ToJSON: Serialize

	template <typename T>
	nlohmann::json ToJSON(const T& _obj)
	{
		return nlohmann::json(_obj);
	}

//}

//{ FromJSON: Deserialize

	template <typename T>
	void FromJSON(T& _obj, const nlohmann::json& _json)
	{
		_obj = _json.get<T>();
	}

//}
}

#endif // GUARD
