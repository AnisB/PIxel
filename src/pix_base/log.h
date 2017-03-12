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

#ifndef BASE_LOG
#define BASE_LOG

// Library includes
#include "string_helper.h"

// STL Includes
#include <iostream>
#include <cstdio>

namespace Pixel
{
	// Defining the different available log levels
	namespace TLogLevel
	{
		enum Type
		{
			DEBUG = 0,
			INFO = 1, 
			WARNING = 2,
			ERROR = 3,
		};	
	}

	// The logger interface that must be overloaded by your custom logger
	class TLoggerInterface
	{
	public:
		TLoggerInterface() {}
		virtual ~TLoggerInterface() {}

		// The virtual logging function that must be overriden
		virtual void Log(TLogLevel::Type _logLevel, const char* _message) = 0;
	};

	// Access the default logger
	TLoggerInterface* default_logger();
	void set_default_logger(TLoggerInterface* _loggerInterface);

	// General print macro
	#define PRINT_GENERAL(LEVEL, ENONCE)\
	{\
		STREAM_TYPE collector;\
		collector << ENONCE;\
		Pixel::TLoggerInterface* logger = Pixel::default_logger();\
		logger->Log(LEVEL, collector.str().c_str());\
	}

	// General purpose MACROS
	#ifdef SILENT
		#define PRINT_DEBUG(TAG, ENONCE) {}
		#define PRINT_INFO(TAG, ENONCE) {}
		#define PRINT_WARNING(TAG, ENONCE) {}
		#define PRINT_ERROR(TAG, ENONCE) {}
	#else
		#define PRINT_DEBUG(ENONCE) PRINT_GENERAL(Pixel::TLogLevel::DEBUG, ENONCE)
		#define PRINT_INFO(ENONCE) PRINT_GENERAL(Pixel::TLogLevel::INFO, ENONCE)
		#define PRINT_WARNING(ENONCE) PRINT_GENERAL(Pixel::TLogLevel::WARNING, ENONCE)
		#define PRINT_ERROR(ENONCE) PRINT_GENERAL(Pixel::TLogLevel::ERROR, ENONCE)
	#endif
}
#endif