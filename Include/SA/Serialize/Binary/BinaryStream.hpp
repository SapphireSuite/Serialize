// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SERIALIZE_BINARY_STREAM_GUARD
#define SAPPHIRE_SERIALIZE_BINARY_STREAM_GUARD

#include <SA/Serialize/Binary/BinarySerializer.hpp>

namespace SA::Ser
{
	class IOBinaryStream
	{
		size_t mOffset  = 0u;

	public:
		std::string bin;

		IOBinaryStream() = default;
		IOBinaryStream(std::string&& _bin);

		template <typename T>
		IOBinaryStream& operator<<(const T& _obj)
		{
			ToBinary(_obj, bin);

			return *this;
		}

		template <typename T>
		IOBinaryStream& operator>>(T& _obj)
		{
			FromBinary(_obj, bin, mOffset);

			return *this;
		}
	};
}

#endif // GUARD
