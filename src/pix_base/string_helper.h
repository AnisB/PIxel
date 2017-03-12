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

#ifndef BASE_STRING_HELPER_H
#define BASE_STRING_HELPER_H

// External includes
#include <string.h>
#include <sstream>
#include <vector>

namespace Pixel
{
	// The string base and types (in case i'd like to move to wstring or whatever)
	#define STRING_TYPE std::string
	#define CHAR_TYPE char
	#define STREAM_TYPE std::stringstream

	// Generic converter to string
	template <typename T>
	STRING_TYPE convertToString(const T& _value)
	{
		STREAM_TYPE stream;
		stream << _value;
		return stream.str();
	}

	// Generic converter from string
	template <typename T>
	T convertFromString(const STRING_TYPE& _string)
	{
		STREAM_TYPE stream(_string);
		T val;
		stream >> val;
		return val;
	}

	// Takes a string and removes multiple spaces from it
	void remove_multiple_spaces(STRING_TYPE& parString);
}

#endif // BASE_STRING_HELPER_H