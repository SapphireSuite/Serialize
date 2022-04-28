// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_BINARY_GUARD
#define SAPPHIRE_SERIALIZE_BINARY_GUARD

#include <SA/Serialize/Methods/Method.hpp>

namespace Sa::Ser
{
    namespace Intl
	{
		void FromBinary(void* _data, uint32_t _size, Reader& _read);
		void ToBinary(const void* _data, uint32_t _size, std::string& _str);
	}

    template <>
    class Serialize<Binary>
    {
    public:
        template<typename T>
        static void From(T& _obj, Reader& _reader)
        {
            Intl::FromBinary(&_obj, sizeof(T), _reader);
        }

        template<typename T>
        static void From(T* _objs, uint32_t _size, Reader& _read)
        {
            if constexpr(TypeSpecs<T>::bContinuousData)
                Intl::FromBinary(_objs, sizeof(T) * _size, _read);
            else
            {
                for (auto it = _objs; it != _objs + _size; ++it)
                    From(*it, _read);
            }
        }


        template<typename T>
        static void To(const T& _obj, std::string& _str)
        {
            Intl::ToBinary(&_obj, sizeof(T), _str);
        }

        template<typename T>
        static void To(const T* _objs, uint32_t _size, std::string& _str)
        {
            if constexpr(TypeSpecs<T>::bContinuousData)
                Intl::ToBinary(_objs, sizeof(T) * _size, _str);
            else
            {
                for (auto it = _objs; it != _objs + _size; ++it)
                    To(*it, _str);
            }
        }
    };
}

#endif // GUARD
