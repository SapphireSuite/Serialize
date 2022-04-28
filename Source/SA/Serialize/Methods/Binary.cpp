// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <cstring> // std::memcpy

#include <SA/Serialize/Methods/Binary.hpp>

namespace Sa::Ser
{
    namespace Intl
    {
        void ToBinary(const void* _data, uint32_t _size, std::string& _str)
        {
            const size_t prevSize = _str.size();

            _str.resize(prevSize + _size);

            std::memcpy(_str.data() + prevSize, _data, _size);
        }

        void FromBinary(void* _data, uint32_t _size, Reader& _read)
        {
            std::memcpy(_data, _read.Data(), _size);

            _read.Increment(_size);
        }
    }
}
