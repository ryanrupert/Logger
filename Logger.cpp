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

Logger::~Logger()
{
	if (method == OFILE || method == BOTH) 
	{
		if(out)
			out.close();
	}
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

void Logger::messagef(std::string mes, std::string file, int line)
{
	if (level == INFO) 
	{
		switch (method)
		{
			case BOTH:
			case CONSOLE:
				std::cout << "[" << file << ", " << line << "] INFO " << mes << std::endl;
				if (method == CONSOLE) 
				{
					break;
				}
			case OFILE:
				out << "[" << file << ", " << line << "] INFO " << mes << std::endl;
				break;
		}
	}
}


template <typename T>
void Logger::variable(T var)
{
	out << var;
}

void Logger::setMethod(Method type, std::string file)
{
	method = type;
	if (method == OFILE || method == BOTH) 
	{
		out.open(file.c_str());
	}
}
