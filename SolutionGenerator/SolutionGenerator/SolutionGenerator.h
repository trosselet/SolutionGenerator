#ifndef SOLUTION_GENERATOR__H
#define SOLUTION_GENERATOR__H

#include "json.hpp"
#include <string>

namespace SolutionGenerator
{
	std::string GenerateGuid();

	int CreateRepository(std::string const& repoName, std::string const& solutionName, std::string const& projectName,
		bool pch, bool vcpkg, bool windows, bool lib);

	int CreateBats(std::string const& repositoryName);
    int CreateBats(std::string const& repositoryName, std::string const& projectName);

    int CreateProject(std::string const& repositoryName,
        std::string const& projectName,
        bool startup,
        bool pch,
        bool vcpkg,
        bool lib,
        bool window);

    int CreateProjectConfig(std::string const& repositoryName,
        std::string const& projectName,
        bool startup,
        bool pch,
        bool vcpkg,
        bool lib,
        bool window);

    int CreateProjectSrc(std::string const& repositoryName,
        std::string const& projectName,
        bool pch,
        bool lib,
        bool window);

}

#endif // !SOLUTION_GENERATOR__H


