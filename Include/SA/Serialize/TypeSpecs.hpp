// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_TYPE_SPECS_GUARD
#define SAPPHIRE_SERIALIZE_TYPE_SPECS_GUARD

#include <type_traits>

namespace Sa::Ser
{
    template <typename T>
    struct TypeSpecs
    {
		    static constexpr bool bContinuousData = std::is_arithmetic<T>::value;
    };
}

#endif // GUARD
