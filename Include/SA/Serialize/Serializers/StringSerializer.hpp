// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_STRING_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_STRING_SERIALIZER_GUARD

#include <string>

#include <SA/Serialize/Serializers/Serializer.hpp>

namespace Sa::Ser
{
    template<typename T, Method method>
    class Serializer<std::basic_string<T>, method>
    {
    public:
        void From(std::basic_string<T>& _inStr, Reader& _read, const std::string& _name = "")
        {
            size_t size = 0;
            Serialize<method>::From(size, _read, _name);

            _inStr.resize(size);

            Serialize<method>::From(_inStr.data(), size, _read, _name);
        }

        void To(const std::basic_string<T>& _inStr, std::string& _str, const std::string& _name = "")
        {
            Serialize<method>::To(_inStr.size(), _str, _name);
            Serialize<method>::To(_inStr.data(), _inStr.size(), _str, _name);
        }
    };
}

#endif // GUARD
