/**
* Created by Ryan Rupert
* Date: 2017-11-26
* Source: None
* This is a class that will used for logging debug info
*/

#include <iostream>
#include <fstream>
#include <string>

#define message(mes) messagef(mess, __FILE__, __LINE__)

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
		void variable(std::string mes, T var);
		template <typename T>
		void variable(T var);

	private:
		bool production;
		Level level;
		Method method;
		std::ofstream out;
};
