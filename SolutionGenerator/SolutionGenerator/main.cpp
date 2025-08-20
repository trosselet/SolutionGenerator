#include <vector>
#include <string>
#include <iostream>
#include <ctime>

#include "main.h"
#include "Settings.h"

int main(int argc, char* argv[])
{
	
	srand(time(nullptr));

	if (argc == 1)
	{
		ERROR_IF(true, "Not Enough arguments \n");
	}

	std::string const& userAction = argv[1];
	if (userAction == "-create") return;
	else if (userAction == "-help") return;


	ERROR_IF(true, "Invalid user action has been performed !");
}
