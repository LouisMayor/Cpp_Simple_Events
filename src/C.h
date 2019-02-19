#pragma once

#include <iostream>
#include "A.h"

class C
{
public:
	C( );
	~C( );

	C( const C& other ) = delete;
	C operator=( const C& other ) = delete;

private:
	static void msg( int id )
	{
		std::printf(  "C: id: %d constructed\n", id );
	}
};
