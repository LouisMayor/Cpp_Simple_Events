#include "C.h"

C::C( )
{
	A::contructed += msg;
}

C::~C( )
{
	A::contructed -= msg;
}