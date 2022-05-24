// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_JSON_STREAM_GUARD
#define SAPPHIRE_SERIALIZE_JSON_STREAM_GUARD

#include <SA/Serialize/JSON/JSONSerializer.hpp>

#include <iostream>

namespace SA::Ser
{
	class JSONStream
	{
		char mInOffset = 0;
		char mOutOffset = 0;

	public:
		nlohmann::json json;

		template <typename T>
		JSONStream& operator<<(const T& _obj)
		{
			json[mInOffset++] = ToJSON(_obj);

			return *this;
		}

		template <typename T>
		JSONStream& operator>>(T& _obj)
		{
			FromJSON(_obj, json[mOutOffset++]);

			return *this;
		}
	};
}

#endif // GUARD
