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
#include <pix_math/vector4i.h>
#include <pix_base/log.h>

int main()
{
	Pixel::Vector4i val1 = Pixel::vector4i(1.0, 2.0, 3.0, 4.0);
	Pixel::Vector4 scalar1 = Pixel::to_vec4(val1);
	Pixel::Vector4i val2 = Pixel::vector4i(3.0, 4.0, 5.0, 6.0);
	Pixel::Vector4 scalar2 = Pixel::to_vec4(val2);

	Pixel::Vector4i res = val1 + val2;
	Pixel::Vector4 scalar_res = Pixel::to_vec4(res);

	PRINT_INFO("INPUT1 :"<<scalar1.x<<" "<<scalar1.y<<" "<<scalar1.z<<" "<<scalar1.w);
	PRINT_INFO("INPUT2 :"<<scalar2.x<<" "<<scalar2.y<<" "<<scalar2.z<<" "<<scalar2.w);
	PRINT_INFO("OUTPUT :"<<scalar_res.x<<" "<<scalar_res.y<<" "<<scalar_res.z<<" "<<scalar_res.w);
	return 0;
}