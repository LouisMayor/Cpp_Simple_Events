#pragma once

#include <iostream>
#include "A.h"

class B
{
public:
	B( );
	~B( );

	B( const B& other ) = delete;
	B operator=( const B& other ) = delete;

private:
	static void msg( int id )
	{
		std::printf( "B: id: %d constructed\n", id );
	}
};
