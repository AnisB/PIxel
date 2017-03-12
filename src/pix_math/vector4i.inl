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

namespace Pixel
{
	__forceinline Vector4i vector4i(float _a, float _b, float _c, float _d)
	{
		Vector4i result;
		result.data = _mm_set_ps(_d, _c, _b, _a);
		return result;
	}

	__forceinline Vector4i operator+(const Vector4i& _v1, const Vector4i& _v2)
	{
		Vector4i result;
		result.data = _mm_add_ps (_v1.data, _v2.data);
		return result;
	}

	__forceinline Vector4 to_vec4(const Vector4i& _v)
	{
		Vector4 result;
		_mm_store_ps(&result.x, _v.data);
		return result;
	}
}