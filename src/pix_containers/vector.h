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

#ifndef CONTAINER_VECTOR_H
#define CONTAINER_VECTOR_H

// Library includes
#include "memory/common.h"

namespace Pixel
{
	// Foward declaration
	class TAllocator;

	template <typename T>
	class TVector
	{
		// Internal values
		const uint64_t MINIMAL_RESIZE_CAPACITY = 10;
		const uint64_t RESIZE_FACTOR = 2;
		// Interval types
		typedef T* iterator;

	public:
		TVector(TAllocator& _alloc)
		: m_alloc(_alloc)
		, m_size(0)
		, m_capacity(0)
		, m_data(nullptr)
		{

		}

		TVector(TAllocator& _alloc, uint64_t _reservedSize)
		: m_alloc(_alloc)
		, m_size(0)
		, m_capacity(0)
		{
			resize(_reservedSize);
		}

		~TVector()
		{
			if(m_capacity)
			{
				for(size_t i = 0; i < m_size; i++)
				{
					m_data[i].~T();
				}
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
				for(int i = _size; i < m_size; ++i)
				{
					m_data[i].~T();
				}
				m_size = _size;
			}
			else if (_size < m_capacity)
			{
				for(int i = _size; i < m_size; ++i)
				{
					new (&m_data[i]) T;
				}
				m_size = _size;
			}
			else
			{
				reserve(std::max(_size, MINIMAL_RESIZE_CAPACITY));
				for(int i  = m_size; i < _size; ++i)
				{
					new (&m_data[i]) T;
				}
				m_size = _size;
			}
			
		}

		inline void clear()
		{
			if(m_capacity)
			{
				for(size_t i = 0; i < m_size; i++)
				{
					m_data[i].~T();
				}
				m_size = 0;
			}
		}

		inline void free()
		{
			if(m_capacity)
			{
				for(size_t i = 0; i < m_size; i++)
				{
					m_data[i].~T();
				}
				m_size = 0;
				m_capacity = 0;
				m_alloc.deallocate(m_data);
			}
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

		void erase(iterator _iterator)
		{
			ASSERT(false);
		}

		inline iterator begin()		 						{return m_data;}
		inline const iterator begin() const 				{return m_data;}
		inline iterator end()								{return m_data + m_size;}
		inline const iterator end() const 					{return m_data + m_size;}

	protected:
		T* m_data;
		uint64_t m_size;
		uint64_t m_capacity;

		TAllocator& m_alloc;
	};
}

#endif // CONTAINER_VECTOR_H