#include "pch.h"
#include "logger.h"

//Initialize Static Variables.
Amen::LoggerLevelE Amen::Logger::m_level = Amen::LoggerLevelE::AMEN_FATAL;
bool Amen::Logger::m_showAlone = false;