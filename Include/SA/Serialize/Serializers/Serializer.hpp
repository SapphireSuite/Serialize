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
        void From(T& _obj, Reader& _read, const std::string& _name = "")
        {
            Serialize<method>::From(_obj, _read, _name);
        }

        void To(const T& _obj, std::string& _str, const std::string& _name = "")
        {
            Serialize<method>::To(_obj, _str, _name);
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
        void From(T& _obj, Reader& _read, const std::string& _name = "")
        {
            Serializer<T, method>().From(_obj, _read, _name);
        }

        template<Method method, typename T>
        T From(Reader& _read, const std::string& _name = "")
        {
            T obj;

            From(obj, _read, _name);

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
        void To(const T& _obj, std::string& _str, const std::string& _name = "")
        {
            Serializer<T, method>().To(_obj, _str, _name);
        }

        template<Method method, typename T>
        std::string To(const T& _obj, const std::string& _name = "")
        {
            std::string out;

            To(_obj, out, _name);

            return out;
        }

    //}
//}
}

#endif // GUARD
