// Created by Daniel Collinson (@SuperSquareBoy) - 2018
#include <iostream>
#include "commandline_args.h"

static cmd::WhiteList g_whiteList[] =
{
	{ "screenwidth",			"Set the window width in pixels i.e 1280" },
	{ "screenheight",			"Set the window height in pixels i.e 720" },
	{ "inputFile",				"Input a file to output logs" },
	{ "unlockall",				"Use this to unlock everything for the user including Career and Loot." }
};
static int g_lowWhiteListSize = sizeof( g_whiteList ) / sizeof( g_whiteList[0] );


int main( int argc, char** argv )
{
	cmd::CommandLineArgs::InitaliseCommandArgs();

	cmd::CommandLineArgs::AddWhiteList(g_whiteList, g_lowWhiteListSize);
	cmd::CommandLineArgs::ParseArgs(argc, argv, true);

	if ( cmd::CommandLineArgs::HasArgument( "unlockall" ) )
	{
		// do stuff
	}

	const char* pMyArgumentValue = nullptr;
	if ( cmd::CommandLineArgs::FindStringValue( "inputfile", pMyArgumentValue ) ) // or check pMyArgumentValue for null
	{
		// do stuff with argument
	}

	int screenWidth = 720;
	cmd::CommandLineArgs::FindIntValue( "sCrEeNWiDtH", screenWidth ); // case insensitive

	getchar();
	return 0;
}