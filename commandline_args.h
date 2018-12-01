// Created by Daniel Collinson (@SuperSquareBoy) - 2018
#pragma once

namespace cmd
{
	struct WhiteList
	{
		const char* m_pCommand;
		const char* m_pDescription; // Short description of the command.
	};

	// Order of setup InitaliseCommandArgs -> AddWhiteList -> ParseArgs
	class CommandLineArgs
	{
	public:

		static void InitaliseCommandArgs();

		// Add all your known commands.
		static void AddWhiteList( const WhiteList whiteList[], int arraySize );
		// Populate the arguments passed into the program.
		static void ParseArgs( int argC, char* const* argV, bool fatalIfNotFound );

		static bool HasArgument( const char* pKey );
		static bool FindStringValue( const char* pKey, const char*& outString );
		static bool FindIntValue( const char* pKey, int& outInt );

		// Example of printing out all the supported arguments.
		static void PrintCommandLineData();
	};
}