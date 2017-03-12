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
#include "string_helper.h"
#include <algorithm>

namespace Pixel
{
	bool both_are_spaces(CHAR_TYPE lhs, CHAR_TYPE rhs) 
	{ 
		return (lhs == rhs) && (lhs == ' '); 
	}

	void remove_multiple_spaces(STRING_TYPE& _str) 
	{
		STRING_TYPE::iterator new_end = std::unique(_str.begin(), _str.end(), both_are_spaces);
		_str.erase(new_end, _str.end());  
	}
}