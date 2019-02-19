#pragma once

#include <functional>
#include <algorithm>
#include <vector>

/* Wanting to create an extremely simple event system. Design based on Unity Actions */

template<typename _rTy, typename _pTy>
class Event
{
public:
	Event( ) = default;

	Event( const Event& other ) = delete;
	Event operator=( const Event& other ) = delete;

	template<typename _ptrFunc>
	void operator+=( _ptrFunc func )
	{
		_funcs.push_back( std::function<_rTy( _pTy )>( func ) );
	}

	template<class _ptrFunc>
	void operator-=( _ptrFunc func )
	{
		std::function<_rTy( _pTy )> to_find( func );
		size_t addr_to_find = get_addr( to_find );

		std::vector <std::vector<std::function < _rTy( _pTy )> >::iterator> to_remove;

		for( auto it = _funcs.begin( ); it != _funcs.end( ); ++it )
		{
			if( addr_to_find == get_addr( *it ) )
			{
				to_remove.push_back( it );
			}
		}

		for (auto &i : to_remove)
		{
			_funcs.erase( i );
		}
	}

	void invoke_safe( _pTy value )
	{
		for( auto &func : _funcs )
		{
			func( value );
		}
	}
private:
	std::vector<std::function<_rTy( _pTy )>> _funcs;

	// src: https://stackoverflow.com/a/18039824
	size_t get_addr( std::function < _rTy( _pTy ) > f )
	{
		typedef _rTy( fnType )( _pTy );
		fnType ** fnPointer = f.template target<fnType*>( );
		return reinterpret_cast<size_t> (*fnPointer);
	}
};
