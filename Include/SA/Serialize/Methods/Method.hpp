// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_METHOD_GUARD
#define SAPPHIRE_SERIALIZE_METHOD_GUARD

#include <SA/Serialize/Reader.hpp>
#include <SA/Serialize/TypeSpecs.hpp>

namespace Sa::Ser
{
    enum Method
    {
        Binary = 1,
        JSON,
        XML,
    };

    template <Method method>
    class Serialize;
}

#endif // GUARD
