// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Binary/BinaryStream.hpp>

namespace SA::Ser
{
	IOBinaryStream::IOBinaryStream(std::string&& _bin) :
		bin{ std::move(_bin) }
	{
	}
}
