/**
* Created by Ryan Rupert
* Date: 2017-11-26
* Source: None
* This is a class that will used for logging debug info
*/

#include <iostream>
#include <fstream>
#include <string>
#include "toStringPatch.h"

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

		template <typename T>
		void varAddressf(Level lev, std::string name, T &var, std::string file, int line);

	private:
		bool production;
		Level level;
		Method method;
		std::ofstream out;
		void log(Level lev, std::string output);
		char Levels[3][8] = { "ERROR", "WARNING", "INFO"};
};
template <typename T>
void Logger::variablef(Level lev, T var, std::string file, int line)
{
	std::string output = "[" + file + ", " + patch::to_string(line) + "] " + Levels[lev] + " " + "( " + patch::to_string(var) + " )";
	log(lev, output);
}
template <typename T>
void Logger::varMessagef(Level lev, std::string mes, T var, std::string file, int line)
{
	std::string output = "[" + file + ", " + patch::to_string(line) + "] " + Levels[lev] + " " + mes + " " + "( " + patch::to_string(var) + " )";
	log(lev, output);
}
template <typename T>
void Logger::varAddressf(Level lev, std::string name, T &var, std::string file, int line)
{
	std::string output = "[" + file + ", " + patch::to_string(line) + "] " + Levels[lev] + " " + name + " " + "( " + &var + " )";
	log(lev, output);
}
