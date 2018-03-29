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
	std::string output = "[" + file + ", " + patch::to_string(line) + "] INFO " + mes;
	log(INFO, output);
}

void Logger::setMethod(Method type, std::string file)
{
	method = type;
	if (method == OFILE || method == BOTH) 
	{
		out.open(file.c_str());
	}
}

void Logger::log(Level lev, std::string output)
{
	if (lev <= level) 
	{
		switch (method)
		{
			case BOTH:
			case CONSOLE:
				std::cout << output << std::endl;
				if (method == CONSOLE) 
				{
					break;
				}
			case OFILE:
				out << output << std::endl;
				break;
		}
	}
}
