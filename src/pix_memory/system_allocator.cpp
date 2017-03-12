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

// Library includes
#include "system_allocator.h"

// External includes
#include <stdlib.h>

namespace Pixel
{
	TSystemAllocator::TSystemAllocator()
	{
		// Nothing to do
	}

	TSystemAllocator::~TSystemAllocator()
	{
		// Nothing to do
	}

	// Allocate a memory chunk give a particular alignement
	memory_block TSystemAllocator::allocate(size_t size, char alignment)
	{
		memory_block blc;
		blc.ptr = malloc(size);
		blc.size  = 0;
		return blc;
	}

	// Frees a memory spot given
	void TSystemAllocator::deallocate(void* _ptr)
	{
		free(_ptr);
	}

	// Function that aswers to the question, has this bloc been allocated by this allocator ?
	bool TSystemAllocator::owns(void* _ptr)
	{
		return true;
	}
}