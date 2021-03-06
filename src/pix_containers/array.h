/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**/

#ifndef CONTAINER_ARRAY_H
#define CONTAINER_ARRAY_H

// Library includes
#include "memory/common.h"

namespace Pixel
{
	// Foward declaration
	class TAllocator;

	template <typename T>
	class TArray
	{
		// Internal values
		const uint64_t MINIMAL_RESIZE_CAPACITY = 10;
		const uint64_t RESIZE_FACTOR = 2;

	public:
		TArray(TAllocator& _alloc)
		: m_alloc(_alloc)
		, m_size(0)
		, m_capacity(0)
		, m_data(nullptr)
		{

		}

		TArray(TAllocator& _alloc, uint64_t _reservedSize)
		: m_alloc(_alloc)
		, m_size(0)
		, m_capacity(0)
		{
			resize(_reservedSize);
		}

		~TArray()
		{
			if(m_capacity)
			{
				m_alloc.deallocate(m_data);
			}
		}

		inline uint64_t size() {return m_size;}
		inline uint64_t capacity() {return m_capacity;}

		void resize(uint64_t _size)
		{
			if(_size ==  0)
			{
				clear();
			}
			else if(_size < m_size)
			{
				m_size = _size;
			}
			else if (_size < m_capacity)
			{
				m_size = _size;
			}
			else
			{
				reserve(std::max(_size, MINIMAL_RESIZE_CAPACITY));
				m_size = _size;
			}
			
		}

		inline void free()
		{
			if(m_capacity)
			{
				m_size = 0;
				m_capacity = 0;
				m_alloc.deallocate(m_data);
			}
		}

		inline void clear()
		{
			m_size = 0;
		}

		void reserve(uint64_t _space)
		{
			ASSERT_NO_RELEASE(_space != 0);
			memory_block mem = m_alloc.allocate(sizeof(T) * (m_capacity + _space));
			memcpy(mem.ptr, m_data, sizeof(T) * m_size);
			if(m_data != nullptr)
			{
				m_alloc.deallocate(m_data);
			}
			m_data = static_cast<T*>(mem.ptr);
			m_capacity = (m_capacity + _space);
		}

		inline T& operator[](int _index)
		{
			ASSERT_NO_RELEASE(_index < m_size);
			return m_data[_index];
		}

		inline void push_back(const T& _value)
		{
			if(m_size >= m_capacity)
			{
				reserve(std::max(m_capacity * RESIZE_FACTOR, MINIMAL_RESIZE_CAPACITY));
			}
			m_data[m_size++] = _value;
		}

	protected:
		T* m_data;
		uint64_t m_size;
		uint64_t m_capacity;

		TAllocator& m_alloc;
	};
}

#endif // CONTAINER_ARRAY_H