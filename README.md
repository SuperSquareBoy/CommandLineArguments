# CommandLineArguments

Easy self documented command line arguments 
Clean, simple interface and readable code.

# The Problem

So during my time on Driveclub one of my biggest issues was command line arguments. It was a massive code base and command line arguments were buried all over the code base. A wiki page would always be outdated and never maintained. Headache for QA when they need to test something but can't remember the command line argument. QA might be using an argument on a build that doesn't feature it and they wouldn't know or a new one was added but not for their current build. Sometimes you couldn't remember if it was the 1 dash or 2 dashes to identify the argument. Headache when trying to remember the case of the argument, was it lower case? Mixed case? There was no consistency with the arguments, each coder has their own preference for the system they were working on. There were times when you'd spell it wrong and you wouldn't know until you came to the section of the software/game you were working with and find out the "instant win race" argument didn't do anything and you wasn't warned about it.

# Solution

For our next project we had a unique opportunity of starting a fresh code base. I came up with this. It was a more strict solution where you effectively register known command line arguments and give a brief description. It was case insensitive and it wouldn’t care about how many dash (-) identifiers an argument had. It would instantly fatal error on boot if an argument you gave the program was not known (spelt wrong, didn’t exist). This saved so much time. Coders had a code file where all known arguments were listed, separated by section (rendering, metagame, server, etc). QA had an always up to date list of all known arguments with each build via the output.

In my solution I've created a clean static interface using built in types to avoid forcing dependencies. I've kept the header file free of include files, all includes are in the c++ for containers. I believe in simple solutions to get the job done, no need to over complicate things. Left some comments in the cpp to replace debugbreak with custom fatal error, same with the cassert.

Thanks.
