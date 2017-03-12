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

#ifndef MEMORY_COMMON_H
#define MEMORY_COMMON_H

// Library includes
#include "allocator.h"

namespace Pixel
{
	// This function sets should be used instead of the classic new operator
	// new operator should be forbitten. 

	// This one concernes all the object that need to be created using a default constructor
	template<typename T>
	T* make_new(TAllocator* _allocator)
	{
		// Allocate the memory space that matches the target type
		memory_block allocated = _allocator->allocate(sizeof(T));
		// Build, cast and return the allocated memory in the right type
		return new (allocated.ptr) T();
	}

	// This one concernes all the object that need to be created using a one parameter constructor
	template<typename T, typename P1>
	T* make_new(TAllocator* _allocator, P1& _p1)
	{
		// Allocate the memory space that matches the target type
		memory_block allocated = _allocator->allocate(sizeof(T));
		// Build, cast and return the allocated memory in the right type
		return new (allocated.ptr) T(_p1);
	}	

	// This one concernes all the object that need to be created using a two parameter constructor
	template<typename T, typename P1, typename P2>
	T* make_new(TAllocator* _allocator, P1& _p1, P2& _p2)
	{
		// Allocate the memory space that matches the target type
		memory_block allocated = _allocator->allocate(sizeof(T));
		// Build, cast and return the allocated memory in the right type
		return new (allocated.ptr) T(_p1, _p2);
	}	

	// This function is the way to delete objects that have been allocated 
	// using a Donut::TAllocator.
	template<typename T>
	void make_delete(T* _targetPtr)
	{
		// Fetch the allocator that has been used for the object
		TAllocator& tarAllocator = _targetPtr->_alloc;
		// Deallocates the memory
		tarAllocator.deallocate(_targetPtr);
	}

	// This function should be called to fetch the default common allocator, if a specific 
	// allocation behavior is not required aat the spot you call it.
	TAllocator* default_allocator();
}

#endif // MEMORY_COMMON_H