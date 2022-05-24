// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_STRING_BINARY_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_STRING_BINARY_SERIALIZER_GUARD

#include <SA/Serialize/Binary/BinarySerializer.hpp>

namespace SA::Ser
{
	template <typename T>
	void ToBinary(const std::basic_string<T>& _str, std::string& _dst)
	{
		ToBinary(_str.size(), _dst);
		ToBinary(_str.data(), _str.size(), _dst);
	}

	template <typename T>
	void FromBinary(std::basic_string<T>& _str, const std::string& _src, size_t& _offset)
	{
		size_t size = 0u;
		FromBinary(size, _src, _offset);

		_str.resize(size);
		FromBinary(_str.data(), size, _src, _offset);
	}
}

#endif // GUARD
