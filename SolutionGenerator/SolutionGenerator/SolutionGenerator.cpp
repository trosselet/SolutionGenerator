#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <windows.h>

#include "Settings.h"
#include "SolutionGenerator.h"

namespace fs = std::filesystem;
namespace SolutionGenerator
{
    int CreateRepository(std::string const& repoName,
        std::string const& solutionName,
        std::string const& projectName,
        bool pch,
        bool vcpkg,
        bool windows,
        bool lib)
    {
        ERROR_IF(fs::exists(repoName) == false && fs::create_directory(repoName) == false,
            "Could not create directory \n")

            ERROR_IF(fs::exists(repoName + "/source"),
                "There's already a solution named " + repoName + "\n")

            ERROR_IF(fs::create_directory(repoName + "/bin") == false, "Could not create bin folder\n")
            ERROR_IF(fs::create_directory(repoName + "/config") == false, "Could not create config folder\n")
            ERROR_IF(fs::create_directory(repoName + "/resource") == false, "Could not create resource folder\n")
            ERROR_IF(fs::create_directory(repoName + "/source") == false, "Could not create source folder\n")

            std::ofstream gitignore(repoName + "/.gitignore");
        gitignore << "ide";
        gitignore.close();

        std::cout << std::string(SUCCESS_COLOR) + ".gitignore created successfully\n" + RESET_COLOR;

        std::cout << std::string(SUCCESS_COLOR) + "Repository (" + repoName + ") created successfully\n" + RESET_COLOR;

        std::ofstream config(repoName + "/config/settings.json");
        // config << CONFIG_SETTINGS(solutionName, GenerateGuid());
        config.close();

        std::cout << std::string(SUCCESS_COLOR) + "settings.json created successfully\n" + RESET_COLOR;

        // ERROR_IF(CreateBats(repoName), "Could not create make.bat file\n")

        std::cout << std::string(SUCCESS_COLOR) + "Solution (" + solutionName + ") created successfully\n" + RESET_COLOR;

        // CHECK_FOR_ERROR(CreateProject(repoName, projectName, true, pch, vcpkg, lib, windows))

        return 0;
    }
}
