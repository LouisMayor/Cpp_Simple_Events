#include "A.h"

Event<void, int> A::contructed;

A::A( )
{
	_id = 1;
	contructed.invoke_safe( _id );
}