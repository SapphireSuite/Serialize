// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_VECTOR_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_VECTOR_SERIALIZER_GUARD

#include <vector>

#include <SA/Serialize/Serializers/Serializer.hpp>

namespace Sa::Ser
{
    template<typename T, Method method>
    class Serializer<std::vector<T>, method>
    {
    public:
        void From(std::vector<T>& _vec, Reader& _read)
        {
            size_t size = 0;
            Serialize<method>::From(size, _read);

            _vec.resize(size);

            Serialize<method>::From(_vec.data(), size, _read);
        }

        void To(const std::vector<T>& _vec, std::string& _str)
        {
            Serialize<method>::To(_vec.size(), _str);
            Serialize<method>::To(_vec.data(), _vec.size(), _str);
        }
    };
}

#endif // GUARD
