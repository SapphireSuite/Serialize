// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_JSON_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_JSON_SERIALIZER_GUARD

#include <json.hpp>

namespace SA
{
	class JSONSerializer
	{
		nlohmann::json mJSON;
	};
}

#endif // GUARD
