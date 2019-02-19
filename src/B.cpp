#include "B.h"

B::B( )
{
	A::contructed += msg;
}

B::~B( )
{
	A::contructed -= msg;
}
