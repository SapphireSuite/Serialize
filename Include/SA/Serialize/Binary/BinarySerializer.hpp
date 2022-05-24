// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_BINARY_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_BINARY_SERIALIZER_GUARD

#include <string>

#include <SA/Serialize/Misc/TypeSpecs.hpp>

namespace SA::Ser
{
//{ ToBinary: Serialize

	namespace Intl
	{
		void ToBinary(const void* _data, size_t _size, std::string& _dst);
	}

	template <typename T>
	void ToBinary(const T& _obj, std::string& _dst);

	template <typename T>
	void ToBinary(const T* _objs, size_t _size, std::string& _dst);

//}

//{ FromBinary: Deserialize

	namespace Intl
	{
		void FromBinary(void* _data, size_t _size, const std::string& _src, size_t &_offset);
	}

	template <typename T>
	void FromBinary(T& _obj, const std::string& _src, size_t& _offset);

	template <typename T>
	void FromBinary(T* _objs, size_t _size, const std::string& _src, size_t& _offset);

//}
}

#include <SA/Serialize/Binary/BinarySerializer.inl>

#endif // GUARD
