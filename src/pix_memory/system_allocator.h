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

#ifndef SYSTEM_ALLOCATOR_H
#define SYSTEM_ALLOCATOR_H

// Library includes
#include "allocator.h"

namespace Pixel
{
	class TSystemAllocator : public TAllocator
	{
	public:
		TSystemAllocator();
		~TSystemAllocator();

		// Allocate a memory chunk give a particular alignement
		virtual memory_block allocate(size_t size, char alignment = 4);

		// Frees a memory spot given
		virtual void deallocate(void* _ptr);

		// Function that aswers to the question, has this bloc
		// been allocated by this allocator ?
		virtual bool owns(void* _ptr);
	};
}

#endif // SYSTEM_ALLOCATOR_H