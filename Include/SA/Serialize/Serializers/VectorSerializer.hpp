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
        void From(std::vector<T>& _vec, Reader& _read, const std::string& _name = "")
        {
            (void)_name;

            size_t size = 0;
            Serialize<method>::From(size, _read, "size");

            _vec.resize(size);

            Serialize<method>::From(_vec.data(), size, _read, "data");
        }

        void To(const std::vector<T>& _vec, std::string& _str, const std::string& _name = "")
        {
            (void)_name;

            Serialize<method>::To(_vec.size(), _str, "size");
            Serialize<method>::To(_vec.data(), _vec.size(), _str, "data");
        }
    };
}

#endif // GUARD
