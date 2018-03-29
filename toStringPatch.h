/************************************
* Copied
* Title: toStringPatch.h
* Author: cMinor
* Date: 20131231
* Code Version: No version given
* Availability: https://stackoverflow.com/a/20861692
************************************/

#include <string>
#include <sstream>

namespace patch
{
	template < typename T >
	std::string to_string( const T& n )
	{
		std::ostringstream stm ;
		stm << n ;
		return stm.str() ;
	}
}
