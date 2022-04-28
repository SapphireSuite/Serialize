// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_SERIALIZER_GUARD
#define SAPPHIRE_SERIALIZE_SERIALIZER_GUARD

#include <SA/Collections/SerializeMethods>

namespace Sa::Ser
{
    /**
     * @brief Default serializer implementation.
     * 
     * @tparam T 
     * @tparam method 
     */
    template<typename T, Method method>
    class Serializer
    {
    public:
        void From(T& _obj, Reader& _read)
        {
            Serialize<method>::From(_obj, _read);
        }

        void To(const T& _obj, std::string& _str)
        {
            Serialize<method>::To(_obj, _str);
        }
    };


//{ Helpers

    //{ From

        /**
         * @brief Helper template deduction From method.
         * 
         * @tparam method 
         * @tparam T 
         * @param _obj 
         * @param _str 
         */
        template<Method method, typename T>
        void From(T& _obj, Reader& _read)
        {
            Serializer<T, method>().From(_obj, _read);
        }

        template<Method method, typename T>
        T From(Reader& _read)
        {
            T obj;

            From(obj, _read);

            return obj;
        }

    //}


    //{ To

        /**
         * @brief Helper template deduction To method.
         * 
         * @tparam method 
         * @tparam T 
         * @param _obj 
         * @param _str 
         */
        template<Method method, typename T>
        void To(const T& _obj, std::string& _str)
        {
            Serializer<T, method>().To(_obj, _str);
        }

        template<Method method, typename T>
        std::string To(const T& _obj)
        {
            std::string out;

            To(_obj, out);

            return out;
        }

    //}
//}
}

#endif // GUARD
