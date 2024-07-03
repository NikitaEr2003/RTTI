#include "MyEx.h"

MyEx::MyEx( const char* msg) :  domain_error(msg), message(msg) {}

const char* MyEx::what() const noexcept
{
	return message;
}



