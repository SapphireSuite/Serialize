// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_BINARY_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_BINARY_SERIALIZER_GUARD

#include <SA/Serialize/Serializer.hpp>

namespace Sa::Ser
{
    namespace Intl
	{
		void FromBinary(void* _data, uint32_t _size, Reader& _read);
		void ToBinary(const void* _data, uint32_t _size, std::string& _str);
	}

    template<typename T>
    class Serializer<T, Method::Binary>
    {
    public:
        static void From(T& _obj, Reader& _reader)
        {
            Intl::FromBinary(&_obj, sizeof(T), _reader);
        }

        static void To(const T& _obj, std::string& _str)
        {
            Intl::ToBinary(&_obj, sizeof(T), _str);
        }
    };
}

#endif // GUARD
