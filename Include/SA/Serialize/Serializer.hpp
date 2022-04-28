// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_SERIALIZER_GUARD

#include <SA/Serialize/Method.hpp>
#include <SA/Serialize/Reader.hpp>

namespace Sa::Ser
{
    template<typename T, Method method>
    class Serializer;


//{ Helpers

    namespace Serialize
    {

    //{ From

        template<Method method, typename T>
        void From(T& _obj, Reader& _reader)
        {
            Serializer<T, method>::From(_obj, _reader);
        }

        template<Method method, typename T>
        T From(Reader& _reader)
        {
            T obj;

            From(obj, _reader);

            return obj;
        }

        template<Method method, typename T>
        void From(T* _objs, uint32_t _size, Reader& _read)
        {
            for (auto it = _objs; it != _objs + _size; ++it)
                From(*it, _read);
        }

    //}


    //{ To

        template<Method method, typename T>
        void To(const T& _obj, std::string& _str)
        {
            Serializer<T, method>::To(_obj, _str);
        }

        template<Method method, typename T>
        std::string To(const T& _obj)
        {
            std::string out;

            To(_obj, out);

            return out;
        }

        template<Method method, typename T>
        void To(const T* _objs, uint32_t _size, std::string& _str)
        {
            for (auto it = _objs; it != _objs + _size; ++it)
                To(*it, _str);
        }

    //}

    }
//}
}

#endif // GUARD
