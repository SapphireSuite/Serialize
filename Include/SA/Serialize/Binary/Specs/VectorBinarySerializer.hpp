// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_VECTOR_BINARY_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_VECTOR_BINARY_SERIALIZER_GUARD

#include <vector>

#include <SA/Serialize/Binary/BinarySerializer.hpp>

namespace SA::Ser
{
	template <typename T>
	void ToBinary(const std::vector<T>& _vec, std::string& _dst)
	{
		ToBinary(_vec.size(), _dst);
		ToBinary(_vec.data(), _vec.size(), _dst);
	}

	template <typename T>
	void FromBinary(std::vector<T>& _vec, const std::string& _src, size_t& _offset)
	{
		size_t size = 0u;
		FromBinary(size, _src, _offset);

		_vec.resize(size);
		FromBinary(_vec.data(), size, _src, _offset);
	}
}

#endif // GUARD
