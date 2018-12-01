// Created by Daniel Collinson (@SuperSquareBoy) - 2018
#include "commandline_args.h"

#include <map>
#include <vector>
#include <iostream>
#include <cassert>

namespace cmd
{
	const unsigned int g_maxNumAllowedCommandArgs = 128;
	const char* g_argIdentifer = "-";

	std::vector< WhiteList > g_whiteList;

	struct customArgsCompare 
	{
		bool operator()( const char* a, const char* b ) const 
		{
			return _stricmp( a, b ) < 0;
		}
	};
	typedef std::map< const char*, const char*, customArgsCompare > ProgramArgs;
	ProgramArgs g_programCommandArgs;

	void StripOffIdentifer( const char*& pStrToStrip )
	{
		assert( pStrToStrip != nullptr ); // Add your own custom assert to remove cassert
		while ( pStrToStrip[0] == *g_argIdentifer )
		{
			pStrToStrip++;
		}
	}

	void CommandLineArgs::InitaliseCommandArgs()
	{
		g_whiteList.clear();
		g_whiteList.reserve( g_maxNumAllowedCommandArgs );
	}

	void CommandLineArgs::AddWhiteList( const WhiteList whiteList[], unsigned int arraySize )
	{
		for ( unsigned int i = 0; i < arraySize; ++i )
		{
			g_whiteList.push_back( whiteList[i] );
			StripOffIdentifer( g_whiteList[ (unsigned int)g_whiteList.size() - 1 ].m_pCommand );
		}
	}

	void CommandLineArgs::ParseArgs( unsigned int argC, char* const* argV, bool fatalIfNotFound )
	{
		for ( unsigned int argIndex = 1; argIndex < argC; ++argIndex )
		{
			const char* pKey = nullptr;
			const char* pValue = nullptr;

			if ( strstr( argV[ argIndex ], g_argIdentifer ) != 0 )
			{
				for ( unsigned int whitelistIdx = 0; whitelistIdx < (int)g_whiteList.size(); ++whitelistIdx )
				{
					const char* pArgCopy = argV[ argIndex ];
					StripOffIdentifer( pArgCopy );
					if ( _stricmp( pArgCopy, g_whiteList[ whitelistIdx ].m_pCommand ) == 0 )
					{
						pKey = pArgCopy;
						break;
					}
				}

				if ( pKey == nullptr )
				{
					if ( fatalIfNotFound )
					{
						// *******
						// Add your favourite fatal error. argV[argIndex] was not a known command
						__debugbreak();
						// *******
					}
					else
					{
						continue;
					}
				}

				// Grab our value if we have one
				const unsigned int next = argIndex + 1;
				if ( next < argC && ( strstr( argV[ next ], g_argIdentifer ) == 0) )
				{
					pValue = argV[ next ];
				}

				g_programCommandArgs.insert( {pKey, pValue} );
			}
		}
		PrintCommandLineData();
	}

	bool CommandLineArgs::HasArgument( const char* pKey )
	{
		return g_programCommandArgs.find(pKey) != g_programCommandArgs.end();
	}

	bool CommandLineArgs::FindStringValue( const char* pKey, const char*& outString )
	{
		ProgramArgs::iterator it = g_programCommandArgs.find( pKey );

		if ( it != g_programCommandArgs.end() )
		{
			outString = it->second;
			return true;
		}
		outString = nullptr;
		return false;
	}

	bool CommandLineArgs::FindIntValue( const char* pKey, int& outInt )
	{
		ProgramArgs::iterator it = g_programCommandArgs.find( pKey );

		if ( it != g_programCommandArgs.end() && it->second )
		{
			outInt = atoi(it->second);
			return true;
		}
		return false;

	}

	void CommandLineArgs::PrintCommandLineData()
	{
		printf( "[CommandLineArgs]:\nAvailable:\n" );

		for( unsigned int i = 0; i < (unsigned int)g_whiteList.size(); ++i )
		{
			printf( "%s -> %s\n", g_whiteList[ i ].m_pCommand, g_whiteList[ i ].m_pDescription );
		}

		printf( "\n[CommandLineArgs]:\nCurrent:\n" );
		for( ProgramArgs::iterator it = g_programCommandArgs.begin(); it != g_programCommandArgs.end(); ++it )
		{
			printf( "%s -> %s\n", it->first, it->second );
		}
	}
}