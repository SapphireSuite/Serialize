// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_READER_GUARD
#define SAPPHIRE_SERIALIZE_READER_GUARD

#include <cstdint>
#include <string>

namespace Sa::Ser
{
	class Reader
	{
		uint32_t mCursor = 0u;
		std::string mStr;

	public:
		Reader(std::string _str) noexcept;

		const char* Data() const noexcept;
		void Increment(uint32_t _incr) noexcept;
	};
}

#endif // GUARD
