// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

namespace SA::Ser
{
//{ ToBinary: Serialize

	template <typename T>
	void ToBinary(const T& _obj, std::string& _dst)
	{
		Intl::ToBinary(&_obj, sizeof(T), _dst);
	}

	template <typename T>
	void ToBinary(const T* _objs, size_t _size, std::string& _dst)
	{
		if (TypeSpecs<T>::bContinuousData)
			Intl::ToBinary(_objs, sizeof(T) * _size, _dst);
		else
		{
			for (auto it = _objs; it != _objs + _size; ++it)
				ToBinary(*it, _dst);
		}
	}

//}

//{ FromBinary: Deserialize

	template <typename T>
	void FromBinary(T& _obj, const std::string& _src, size_t& _offset)
	{
		Intl::FromBinary(&_obj, sizeof(T), _src, _offset);
	}

	template <typename T>
	void FromBinary(T* _objs, size_t _size, const std::string& _src, size_t& _offset)
	{
		if (TypeSpecs<T>::bContinuousData)
			Intl::FromBinary(_objs, sizeof(T) * _size, _src, _offset);
		else
		{
			for (auto it = _objs; it != _objs + _size; ++it)
				FromBinary(*it, _src, _offset);
		}
	}

//}
}
