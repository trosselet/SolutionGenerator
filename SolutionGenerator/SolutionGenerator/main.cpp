#include <vector>
#include <string>
#include <iostream>
#include <ctime>

#include "main.h"
#include "Settings.h"
#include "SolutionGenerator.h"


int Help(int argc, char* argv[])
{
	return 0;
}

int Create(int argc, char* argv[])
{
	if (argc <= 4)
	{
		ERROR_IF(true, "Not enough arguments were provided \n")
	}

	std::string const& repositoryName = argv[2];
	std::string const& solutionName = argv[3];
	std::string projectName = solutionName;

	bool pch = false;
	bool vcpkg = false;
	bool win = false;
	bool lib = false;

	if (argc != 4)
	{
		unsigned int index = 4;
		std::string const& name = argv[4];
		if (name[0] != '-')
		{
			projectName = name;
			index++;
		}
		
		for (unsigned int i = index; i < argc; i++)
		{
			std::string const& argvIndex = argv[i];
			if (argvIndex == "-pch")
			{
				pch = true;
			}
			else if (argvIndex == "-vcpkg")
			{
				vcpkg = true;
			}
			else if (argvIndex == "-win")
			{
				win = true;
			}
			else if (argvIndex == "-lib")
			{
				lib = true;
			}
			else
			{
				return 1;
			}

		}

	}

	CHECK_FOR_ERROR(CreateRepository(repositoryName, solutionName, projectName, pch, vcpkg, win, lib));

	return 0;
}

int Make(int argc, char* argv[])
{
	return 0;
}

int Add(int argc, char* argv[])
{
	return 0;
}

int Edit(int argc, char* argv[])
{
	return 0;
}

int Rename(int argc, char* argv[])
{
	return 0;
}

int AddPortVcpkg(int argc, char* argv[])
{
	return 0;
}

int Remove(int argc, char* argv[])
{
	return 0;
}

int main(int argc, char* argv[])
{
	
	srand(time(nullptr));

	if (argc == 1)
	{
		ERROR_IF(true, "Not Enough arguments \n");
	}

	std::string const& userAction = argv[1];
	if (userAction == "-create") return Create(argc, argv);
	if (userAction == "-help") return 0;


	ERROR_IF(true, "Invalid user action has been performed \n");
}