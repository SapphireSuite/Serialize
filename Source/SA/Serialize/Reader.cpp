// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Reader.hpp>

namespace Sa::Ser
{
	Reader::Reader(std::string _str) noexcept :
		mStr{ std::move(_str) }
	{
	}


	const char* Reader::Data() const noexcept
	{
		return mStr.data() + mCursor;
	}

	void Reader::Increment(uint32_t _incr) noexcept
	{
		mCursor += _incr;
	}
}
