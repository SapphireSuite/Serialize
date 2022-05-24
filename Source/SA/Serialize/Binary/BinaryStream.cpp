// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Binary/BinaryStream.hpp>

namespace SA::Ser
{
	BinaryStream::BinaryStream(std::string&& _bin) :
		bin{ std::move(_bin) }
	{
	}
}
