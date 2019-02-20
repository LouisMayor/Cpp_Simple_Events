#include "Event.hpp"
#include "C.h"
#include "B.h"

void add_one (int x )
{
	x += 1;
}

void add_two( int x )
{
	x += 2;
}

int global_x = 0;

void set_x( int x )
{
	global_x = x;
}

int main()
{
	static Event<int> change_pos;

	change_pos += set_x;

	std::printf( "Current X Pos: %d\n", global_x );

	change_pos.invoke_safe( 50 );
	std::printf( "Position Change Event invoked\n" );

	std::printf( "New X Pos: %d\n", global_x );

	change_pos -= set_x;

	// event
	static Event<int> something_happened;

	// something registering a function to call
	something_happened += add_one;
	something_happened += add_two;

	// event being invoked
	something_happened.invoke_safe( 5 );

	// something unregistering a function
	something_happened -= add_one;
	something_happened -= add_two;

	C tm1;
	B tm2;
	A tm3;

	std::cin.get( );
	return 0;
}
