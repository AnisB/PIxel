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
	// Constructors;
	Vector4 vector4(const double _x, const double _y, const double _z, const double _w)
	{
		Vector4 out;
		out.x = _x;
		out.y = _y;
		out.z = _z;
		out.w = _w;
		return out;
	}
	Vector4 vector4(const double _v)
	{
		Vector4 out;
		out.x = _v;
		out.y = _v;
		out.z = _v;
		out.w = _v;
		return out;
	}

	// Operators
	Vector4 operator*(const Vector4& _v1, double _factor)
	{
		return vector4(_v1.x*_factor,  _v1.y*_factor, _v1.z*_factor, _v1.w*_factor);
	}

	Vector4 operator/(const Vector4& _v1, double _factor)
	{
		return vector4(_v1.x/_factor,  _v1.y/_factor, _v1.z/_factor, _v1.w/_factor);
	}

	Vector4 operator+(const Vector4& _v1, const Vector4& _v2)
	{
		return vector4(_v1.x + _v2.x, _v1.y + _v2.y, _v1.z + _v2.z,  _v1.w + _v2.w);
	}

	Vector4 operator-(const Vector4& _v1, const Vector4& _v2)
	{
		return vector4(_v1.x - _v2.x, _v1.y - _v2.y, _v1.z - _v2.z, _v1.w - _v2.w);
	}

	// Cannonic operations
	double dot(const Vector4& _v1, const Vector4& _v2)
	{
		return _v1.x * _v2.x + _v1.y * _v2.y + _v1.z * _v2.z+ _v1.w * _v2.w;
	}

	Vector4 cross(const Vector4& _v1, const Vector4& _v2)
	{
		return vector4(_v1.y*_v2.z - _v1.z * _v2.y, _v1.z*_v2.x - _v1.x * _v2.z, _v1.x*_v2.y - _v1.y * _v2.x, 0.0);
	}

	double length(const Vector4& _v1)
	{
		return sqrt(_v1.x * _v1.x + _v1.y * _v1.y + _v1.z * _v1.z + _v1.w * _v1.w);
	}

	double length_squared(const Vector4& _v1)
	{
		return (_v1.x * _v1.x + _v1.y * _v1.y + _v1.z * _v1.z + _v1.w * _v1.w);
	}

	inline Vector4 normalize(const Vector4& _vec)
	{
		const double norm = length(_vec);
		return vector4(_vec.x / norm, _vec.y / norm, _vec.z / norm, _vec.w / norm);
	}
}