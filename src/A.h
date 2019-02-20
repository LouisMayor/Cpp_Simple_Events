#pragma once

#include "Event.hpp"

class A
{
public:
	A( );

	A( const A& other ) = delete;
	A operator=( const A& other ) = delete;

	static Event<int> contructed;
private:
	int _id;
};
