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

#ifndef BASE_MACRO
#define BASE_MACRO

namespace Pixel
{
	#if WIN32
		#define FUNCTION_NAME __func__
	#else
		#define FUNCTION_NAME __PRETTY_FUNCTION__
	#endif

	#define __forceinline inline
}

#endif // BASE_MACRO