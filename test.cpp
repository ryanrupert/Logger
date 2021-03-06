/**
* Created by Ryan Rupert
* Date: 2018-03-28
* Source: None
* This is the file that will be used for testing
*/

#include "Logger.h"

int main()
{
	Logger log;
	log.setLevel(Logger::WARNING);
	log.setMethod(Logger::BOTH, "test.txt");
	//log.setProd(true);
	int temp = 5;

	log.message("test");
	log.variable(Logger::WARNING, "test");
	log.varMessage(Logger::ERROR, "test", 1);
	log.varMessage(Logger::ERROR, "temp var", temp);
	log.varAddress(Logger::ERROR, "temp var", temp);
	std::cout << "this is non-log" << std::endl;
	return 0;
}
