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
#include "log.h"
#include "system_logger.h"

namespace Pixel
{
	// This the default logger we provide for the user
	TSystemLogger __defaultLogger;
	TLoggerInterface* defaultLogger = &__defaultLogger;

	// Access the default logger
	TLoggerInterface* default_logger()
	{
		return defaultLogger;
	}

	void set_default_logger(TLoggerInterface* _loggerInterface)
	{
		defaultLogger = _loggerInterface;
	}
}