#pragma once
#include <core/core.h>
#include <iostream>
#include <sstream>

#ifdef AMEN_WINDOWS
	#include <Windows.h>
#endif

namespace Amen
{
	enum class LoggerLevelE
	{
		AMEN_TRACE, //White
		AMEN_INFO,	//Green
		AMEN_WARN,	//Yellow
		AMEN_ERROR,	//Red
		AMEN_FATAL	//Purple
	};

	class AMEN_API Logger
	{
		public:

		/**
		* Set the level of the logger.
		* 
		* @param level The upper barrier of the logging filter. The logger will print all the log levels
		* up to that level in the order that is specified in the Amen::LoggerLevelE enum. Default it FATAL.
		*/
		inline static void SetLevel(LoggerLevelE level) { m_level = level; }

		/**
		* Set show alone.
		* 
		* @param enabled If true then only the Level [SetLevel()] that was set will be logged.
		Else, all the log levels will be logged up to SetLevel() (what ever level you set
		in the order of the LoggerLevelE enum. 
		*
		*/
		inline static void SetShowAlone(bool enable) { m_showAlone = enable; }


		/**
		* Get the level of the logger.
		* 
		* @return The LoggerLevelE that i currently set.
		*/
		inline static LoggerLevelE GetLevel() { return m_level; }

		/**
		* Get the show alone flag.
		* 
		* @return If true then only the Level [SetLevel()] that was set will be logged.
		Else, all the log levels will be logged up to SetLevel() (what ever level you set
		in the order of the Amen::LoggerLevelE enum. 
		*
		*/
		inline static bool GetShowAlone() { return m_showAlone; }

		private:
		static bool m_showAlone;
		static LoggerLevelE m_level;
		
	};
}


#if defined(AMEN_LINUX) && defined(AMEN_DEBUG)
	#define AMEN_COLOR_RED 		"\e[1;31m"
	#define AMEN_COLOR_GREEN 	"\e[1;32m"
	#define AMEN_COLOR_YELLOW 	"\e[1;33m"
	#define AMEN_COLOR_BLUE 	"\e[1;34m"
	#define AMEN_COLOR_CYAN 	"\e[1;36m"
	#define AMEN_COLOR_PURPLE	"\e[1;35m"
	#define AMEN_COLOR_END 		"\e[0m"

	#define AMEN_VA_ARGS(...) , ##__VA_ARGS__

	#define AMEN_COLORED_PRINT(color, fmt, ...)\
	{\
		std::stringstream amen_colored_printf_stream_helper;\
		amen_colored_printf_stream_helper << color << fmt << AMEN_COLOR_END << "\n";\
		printf( amen_colored_printf_stream_helper.str().c_str() AMEN_VA_ARGS(__VA_ARGS__) );\
	}




#elif defined(AMEN_WINDOWS) && defined(AMEN_DEBUG)

	#define AMEN_COLOR_RED		4
	#define AMEN_COLOR_GREEN	2
	#define AMEN_COLOR_YELLOW	6
	#define AMEN_COLOR_BLUE		1
	#define AMEN_COLOR_CYAN		3
	#define AMEN_COLOR_PURPLE	5
	#define AMEN_COLOR_END		7


	#define AMEN_COLORED_PRINT(color, fmt, ...)\
	{\
		std::stringstream amen_colored_printf_stream_helper;\
		amen_colored_printf_stream_helper << fmt << "\n";\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);\
		printf(amen_colored_printf_stream_helper.str().c_str(), __VA_ARGS__);\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AMEN_COLOR_END);\
	}




#else
	#define AMEN_COLOR_RED
	#define AMEN_COLOR_GREEN
	#define AMEN_COLOR_YELLOW
	#define AMEN_COLOR_BLUE
	#define AMEN_COLOR_CYAN
	#define AMEN_COLOR_PURPLE
	#define AMEN_COLOR_END

	#define AMEN_COLORED_PRINT(color, fmt, ...)
#endif




#ifdef AMEN_DEBUG

	#define AMEN_TRACE(fmt, ...)\
	{\
		if (Amen::Logger::GetShowAlone())\
		{\
			if (Amen::Logger::GetLevel() == Amen::LoggerLevelE::AMEN_TRACE)\
				AMEN_COLORED_PRINT(AMEN_COLOR_END, fmt, __VA_ARGS__);\
		}\
		\
		else\
		{\
			if (Amen::Logger::GetLevel() >= Amen::LoggerLevelE::AMEN_TRACE)\
				AMEN_COLORED_PRINT(AMEN_COLOR_END, fmt, __VA_ARGS__);\
		}\
	}




	#define AMEN_INFO(fmt, ...)\
	{\
		if (Amen::Logger::GetShowAlone())\
		{\
			if (Amen::Logger::GetLevel() == Amen::LoggerLevelE::AMEN_INFO)\
				AMEN_COLORED_PRINT(AMEN_COLOR_GREEN, fmt, __VA_ARGS__);\
		}\
		\
		else\
		{\
			if (Amen::Logger::GetLevel() >= Amen::LoggerLevelE::AMEN_INFO)\
				AMEN_COLORED_PRINT(AMEN_COLOR_GREEN, fmt, __VA_ARGS__);\
		}\
	}



	#define AMEN_WARN(fmt, ...)\
	{\
		if (Amen::Logger::GetShowAlone())\
		{\
			if (Amen::Logger::GetLevel() == Amen::LoggerLevelE::AMEN_WARN)\
				AMEN_COLORED_PRINT(AMEN_COLOR_YELLOW, fmt, __VA_ARGS__);\
		}\
		\
		else\
		{\
			if (Amen::Logger::GetLevel() >= Amen::LoggerLevelE::AMEN_WARN)\
				AMEN_COLORED_PRINT(AMEN_COLOR_YELLOW, fmt, __VA_ARGS__);\
		}\
	}




	#define AMEN_ERROR(fmt, ...)\
	{\
		if (Amen::Logger::GetShowAlone())\
		{\
			if (Amen::Logger::GetLevel() == Amen::LoggerLevelE::AMEN_ERROR)\
				AMEN_COLORED_PRINT(AMEN_COLOR_RED, fmt, __VA_ARGS__);\
		}\
		\
		else\
		{\
			if (Amen::Logger::GetLevel() >= Amen::LoggerLevelE::AMEN_ERROR)\
				AMEN_COLORED_PRINT(AMEN_COLOR_RED, fmt, __VA_ARGS__);\
		}\
	}




	#define AMEN_FATAL(fmt, ...)\
	{\
		if (Amen::Logger::GetShowAlone())\
		{\
			if (Amen::Logger::GetLevel() == Amen::LoggerLevelE::AMEN_FATAL)\
				AMEN_COLORED_PRINT(AMEN_COLOR_PURPLE, fmt, __VA_ARGS__);\
		}\
		\
		else\
		{\
			if (Amen::Logger::GetLevel() >= Amen::LoggerLevelE::AMEN_FATAL)\
				AMEN_COLORED_PRINT(AMEN_COLOR_PURPLE, fmt, __VA_ARGS__);\
		}\
	}




#else
	#define AMEN_TRACE(fmt, ...)
	#define AMEN_INFO(fmt, ...)
	#define AMEN_WARN(fmt, ...)
	#define AMEN_ERROR(fmt, ...)
	#define AMEN_FATAL(fmt, ...)

#endif