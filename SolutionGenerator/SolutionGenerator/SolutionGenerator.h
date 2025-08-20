#ifndef SOLUTION_GENERATOR__H
#define SOLUTION_GENERATOR__H

#include <string>

namespace SolutionGenerator
{

	int CreateRepository(std::string const& repoName, std::string const& solutionName, std::string const& projectName,
		bool pch, bool vcpkg, bool windows, bool lib);


}

#endif // !SOLUTION_GENERATOR__H


