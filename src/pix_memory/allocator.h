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

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

// External includes
#if __posix__
	#include <unistd.h>
#elif WIN32
#endif

namespace Pixel
{
	// Memory allocation
	struct memory_block
	{
		void* ptr;
		size_t size;
	};

	// Generic allocator that implements the basic function of an allocator
	class TAllocator
	{
	public:
		TAllocator();
		virtual ~TAllocator();

		// Allocate a memory chunk give a particular alignement
		virtual memory_block allocate(size_t size, char alignment = 4) = 0;

		// Frees a memory spot given
		virtual void deallocate(void* _ptr) = 0;

		// Function that aswers to the question, has this bloc
		// been allocated by this allocator ?
		virtual bool owns(void* _ptr) = 0;
	};
}

#endif // ALLOCATOR_H