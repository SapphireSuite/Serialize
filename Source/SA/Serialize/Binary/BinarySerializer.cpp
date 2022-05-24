// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Binary/BinarySerializer.hpp>

#include <cstring>

namespace SA::Ser
{
	namespace Intl
	{
		void FromBinary(void* _data, size_t _size, const std::string& _src, size_t& _offset)
		{
			std::memcpy(_data, _src.data() + _offset, _size);
			
			_offset += _size;
		}
		
		void ToBinary(const void* _data, size_t _size, std::string& _dst)
		{
			const size_t prevSize = _dst.size();

			_dst.resize(prevSize + _size);

			std::memcpy(_dst.data() + prevSize, _data, _size);
		}
	}
}
