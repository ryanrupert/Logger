/**
* Created by Ryan Rupert
* Date: 2017-11-26
* Source: None
* This is a class that will used for logging debug info
*/

#include <iostream>
#include <fstream>
#include <string>

//function macros
#define varMessage(lev, mes, var) varMessagef(lev, mes, var, __FILE__, __LINE__)
#define variable(lev, var) variablef(lev, var, __FILE__, __LINE__)
#define message(mes) messagef(mes, __FILE__, __LINE__)

class Logger
{
	public:
		enum Level { ERROR, WARNING, INFO };
		enum Method { CONSOLE, OFILE, BOTH };
		Logger();
		~Logger();
		void setProd(bool prod);
		void setLevel(Level lev);
		void setMethod(Method type);
		void setMethod(Method type, std::string file);
		void messagef(std::string mes, std::string file, int line);
		template <typename T>
		void varMessagef(Level lev, std::string mes, T var, std::string file, int line);
		template <typename T>
		void variablef(Level lev, T var, std::string file, int line);

	private:
		bool production;
		Level level;
		Method method;
		std::ofstream out;
		char Levels[3][8] = { "ERROR", "WARNING", "INFO"};
};
template <typename T>
void Logger::variablef(Level lev, T var, std::string file, int line)
{
	if (lev <= level) 
	{
		switch (method)
		{
			case BOTH:
			case CONSOLE:
				std::cout << "[" << file << ", " << line << "] " << Levels[lev] << " ( " << var << " )" << std::endl;

				if (method == CONSOLE) 
				{
					break;
				}
			case OFILE:
				out << "[" << file << ", " << line << "] " << Levels[lev] << " ( " << var << " )" << std::endl;
				break;
		}
	}
}
template <typename T>
void Logger::varMessagef(Level lev, std::string mes, T var, std::string file, int line)
{
	if (lev <= level) 
	{
		switch (method)
		{
			case BOTH:
			case CONSOLE:
				std::cout << "[" << file << ", " << line << "] " << Levels[lev] << " " << mes << " " << "( " << var << " )" << std::endl;

				if (method == CONSOLE) 
				{
					break;
				}
			case OFILE:
				out << "[" << file << ", " << line << "] " << Levels[lev] << " " << mes << " " << "( " << var << " )" << std::endl;
				break;
		}
	}
}
