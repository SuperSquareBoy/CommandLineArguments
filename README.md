# CommandLineArguments

Easy self documented command line arguments 

# The Problem

So during my time on Driveclub one of my biggest issues was command line arguments. It was a massive code base and command line arguments were buried all over the code base. A wiki page would always be outdated and never maintained. Headache for QA when they need to test something but can't remember the command line argument. Headache when you can't remember if it was the 1 dash or 2 dashes to identify the argument. Headache when trying to remember the case of the argument, was it lower case? Mixed case? There were times when you'd spell it wrong and you wouldn't know until you came to the section of the software/game you were working with and find out the "instant win race" argument didn't do anything and you wasn't warned about it.

# Solution

For our next project we had a unique opportunity of starting a fresh code base. I came up with this. It was a more strict solution where you effectively register known command line arguments and give a brief description. It was case insensitive and it wouldn’t care about how many dash (-) identifiers an argument had. It would instantly fatal error on boot if an argument you gave the program was not known (spelt wrong, didn’t exist). This saved so much time. Coders had a code file where all known arguments were listed, separated by section (rendering, metagame, server, etc). QA had an always up to date list of all known arguments with each build via the output.
