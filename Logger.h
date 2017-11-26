/**
* Created by Ryan Rupert
* Date: 2017-11-26
* Source: None
* This is a class that will used for logging debug info
*/

#include <iostream>
#include <fstream>

template<typename T>

class Logger
{
	public:
		enum Level { ERROR, WARNING, INFO };
		enum Method { CONSOLE, OFILE, BOTH };
		~Logger();
		void setProd(bool prod);
		void setLevel(Level lev);
		void setMethod(Method type);
		void setMothod(Method type, std::string file);
		void message(std::string mes);
		void variable(std::string mes, T var);
		void variable(T var);

	private:
		bool production = false;
		Level level = ERROR;
		Method method = CONSOLE;
		void log();
};
