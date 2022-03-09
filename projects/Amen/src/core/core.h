#pragma once
#include <iostream>


#if defined(AMEN_WINDOWS)

	#ifdef AMEN_BUILD
		#define AMEN_API __declspec(dllexport)
	#else
		#define AMEN_API __declspec(dllimport)
	#endif

#elif defined(AMEN_LINUX)
	#define AMEN_API

#else
	#define AMEN_API

#endif




#ifdef AMEN_DEBUG
	#define AMEN_ASSERT(cond, fmt, ...)\
	{\
		if ( !(cond) )\
		{\
			std::stringstream stream;\
			stream << "Assertion FAILED: " << fmt << std::endl << "\tFile: " << __FILE__ << std::endl << "\tLine: " << __LINE__;\
			AMEN_ERROR(stream.str().c_str(), __VA_ARGS__)\
			printf("(Thread Blocked) Press ENTER to exit...");\
			std::cin.get();\
			std::exit(-1);\
		}\
	}

#else
	#define AMEN_ASSERT(cond, fmt, ...)

#endif


//If we are running through Visual Studio, we are relative to the client project.
#ifdef _MSC_VER
	#define AMEN_RELATIVE(path) std::string("../Amen/") + std::string(path)


//If we are running through the command line, concatenate the path relative to the project's root dir.
#else
	#define AMEN_RELATIVE(path) std::string("projects/Amen/") + std::string(path)

#endif



#define AMEN_TOSTRING(symbol) #symbol


#define AMEN_BIND(method) std::bind(&method, this, std::placeholders::_1)