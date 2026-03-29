#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
	private:
		T *_data;
		size_t _size;

	public:
		Array() : _data(nullptr), _size(0) {}
		Array(size_t size): _data(new T[size]), _size(size) {}

		Array(const Array &other)
		{
			if (this != &other)
			{
				_size = other._size;
				_data = new T[_size];
				for (size_t i = 0; i < _size; i++)
					_data[i] = other._data[i];
			}
		}

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] _data;
				_size = other._size;
				_data = new T[_size];
				for (size_t i = 0; i < _size; i++)
					_data[i] = other._data[i];
			}
			return (*this);
		}

		~Array()
		{
			delete[] _data;
		}

		T &operator[](size_t pos)
		{
			if (pos >= _size)
				throw std::out_of_range("index out of bounds");
			return _data[pos];
		}

		const T &operator[](size_t pos) const
		{
			if (pos >= _size)
				throw std::out_of_range("index out of bounds");
			return _data[pos];
		}

		size_t size() const
		{
			return (_size);
		}

};

#endif