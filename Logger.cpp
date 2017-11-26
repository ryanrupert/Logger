/**
* Created by Ryan Rupert
* Date: 2017-11-26
* Source: None
* This is a class that will be used for logging debug info
*/

#include "Logger.h"

void Logger::setProd(bool prod)
{
	production = prod;
}

void Logger::setLevel(Level lev)
{
	level = lev;
}

void Logger::setMethod(Method type)
{
	method = type;
}
