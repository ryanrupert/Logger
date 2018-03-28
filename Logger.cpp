/**
* Created by Ryan Rupert
* Date: 2017-11-26
* Source: None
* This is a class that will be used for logging debug info
*/

#include "Logger.h"


Logger::Logger()
{
	production = false;
	level = ERROR;
	method = CONSOLE;
}

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

void Logger::setMethod(Method type, std::string file)
{
	method = type;
	if (method == OFILE || method == BOTH) 
	{
		out.open(file.c_str());
	}
}

void Logger::message(std::string mes)
{
	out << std::endl;
	out << mes << " ";
}

void Logger::variable(std::string mes, T var)
{
	out << mes << " " << var << " ";
}

void Logger::variable(T var)
{
	out << var;
}
