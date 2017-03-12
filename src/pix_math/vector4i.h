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

#ifndef MATH_INTRINSIC_VECTOR4_H
#define MATH_INTRINSIC_VECTOR4_H

// Library includes
#include "types.h"
#include "pix_base/macro.h"

// External includes
#include <xmmintrin.h>

namespace Pixel
{
	struct Vector4i
	{
		__m128 data;
	};

	__forceinline Vector4i vector4i(float _a, float _b, float _c, float _d);
	__forceinline Vector4i operator+(const Vector4i& _v1, const Vector4i& _v2);
	__forceinline Vector4 to_vec4(const Vector4i& _v);
}


#include "vector4i.inl"

#endif // MATH_INTRINSIC_VECTOR4_H
