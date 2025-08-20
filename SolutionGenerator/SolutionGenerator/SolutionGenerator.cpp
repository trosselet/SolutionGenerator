#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <windows.h>
#include "Utils.h"
#include "Settings.h"
#include "SolutionGenerator.h"

namespace fs = std::filesystem;
namespace SolutionGenerator
{
    std::string GenerateGuid()
    {
        std::string result;
        Utils::DecimalToHexadecimal(rand(), result);
        Utils::DecimalToHexadecimal(rand(), result);
        result += '-';
        Utils::DecimalToHexadecimal(rand(), result);
        result += '-';
        Utils::DecimalToHexadecimal(rand(), result);
        result += '-';
        Utils::DecimalToHexadecimal(rand(), result);
        result += '-';
        Utils::DecimalToHexadecimal(rand(), result);
        Utils::DecimalToHexadecimal(rand(), result);
        Utils::DecimalToHexadecimal(rand(), result);
        return result;
    }


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

        std::cout << SUCCESS_COLOR".gitignore created successfully\n" RESET_COLOR;

        std::cout << SUCCESS_COLOR "Repository (" + repoName + ") created successfully\n" RESET_COLOR;

        std::ofstream config(repoName + "/config/settings.json");
        config << CONFIG_SETTINGS(solutionName, GenerateGuid());
        config.close();

        std::cout << SUCCESS_COLOR "settings.json created successfully\n" RESET_COLOR;

        ERROR_IF(CreateBats(repoName), "Could not create make.bat file\n")

        std::cout << SUCCESS_COLOR  "Solution (" + solutionName + ") created successfully\n" RESET_COLOR;

        CHECK_FOR_ERROR(CreateProject(repoName, projectName, true, pch, vcpkg, lib, windows))

        return 0;
    }

    int CreateBats(std::string const& repositoryName)
    {
        std::ofstream makeBats(repositoryName + "/bin/make.bat");
        makeBats << "cd ../.."  "\n";
        makeBats << "./SolutionGenerator.exe -make " + repositoryName;
        makeBats.close();

        std::cout << SUCCESS_COLOR "make.bat generate successfuly \n" RESET_COLOR;

        std::ofstream makeBatsClear(repositoryName + "/bin/make-clear.bat");
        makeBatsClear << "cd ../.."  "\n";
        makeBatsClear << "./SolutionGenerator.exe -make " + repositoryName + " -clear";
        makeBatsClear.close();

        std::cout << SUCCESS_COLOR "make-clear.bat generate successfuly \n" RESET_COLOR;

        return 0;
    }

    int CreateBats(std::string const& repositoryName, std::string const& projectName)
    {
        std::string projectNameLowerCase = projectName;
        std::transform(projectNameLowerCase.begin(), projectNameLowerCase.end(), projectNameLowerCase.begin(), [](unsigned char const c) { return std::tolower(c); });

        std::ofstream makeFileWrite(repositoryName + "/bin/make-" + projectNameLowerCase + ".bat");
        makeFileWrite <<
            "cd ../.."                                                "\n"
            "SolutionGenerator.exe -make " + repositoryName + " " + projectName;
        makeFileWrite.close();

        std::cout << SUCCESS_COLOR "make-" + projectNameLowerCase + ".bat created successfully\n" RESET_COLOR;

        std::ofstream makeClearFileWrite(repositoryName + "/bin/make-" + projectNameLowerCase + "-clear.bat");
        makeClearFileWrite <<
            "cd ../.."                                                           "\n"
            "SolutionGenerator.exe -make " + repositoryName + " " + projectName + " -clear";
        makeClearFileWrite.close();

        std::cout << SUCCESS_COLOR "make-" + projectNameLowerCase + "-clear.bat created successfully\n" RESET_COLOR;

        return 0;
    }

    int CreateProject(std::string const& repositoryName, std::string const& projectName, bool startup, bool pch, bool vcpkg, bool lib, bool window)
    {
        ERROR_IF(lib && window, "You can't have a windows project and also a static library project");

        CHECK_FOR_ERROR(CreateProjectConfig(repositoryName, projectName, startup, pch, vcpkg, lib, window))

        CHECK_FOR_ERROR(CreateProjectSrc(repositoryName, projectName, pch, lib, window))

        ERROR_IF(fs::create_directory(repositoryName + "/resource/" + projectName) == false, "Couldn't create project (" + projectName + ") resource folder")

        if (lib == false)
        {
            CHECK_FOR_ERROR(CreateBats(repositoryName, projectName))
        }

        std::cout << SUCCESS_COLOR "Project (" + projectName + ") created successfully\n" RESET_COLOR;

        return 0;
    }
    int CreateProjectConfig(std::string const& repositoryName, std::string const& projectName, bool startup, bool pch, bool vcpkg, bool lib, bool window)
    {
        std::string const configFilePath = repositoryName + "/config/settings.json";
        std::ifstream configFile(configFilePath);

        nlohmann::json jsonSettings = nlohmann::json::parse(configFile);
        configFile.close();

        ERROR_IF(jsonSettings["projects"].contains(projectName), "Project " + (projectName)+" already exist in this repository (" + (repositoryName)+")\n");

        if (vcpkg) CHECK_FOR_ERROR(CreateVcpkgJson(repositoryName; projectName));

        std::string guid = GenerateGuid();

        jsonSettings["projects"][projectName] = nlohmann::json::parse(PROJECT_CONFIG);
        jsonSettings["projects"][projectName]["guid"] = guid;
        jsonSettings["projects"][projectName]["pch"] = pch;
        jsonSettings["projects"][projectName]["vcpkg"] = vcpkg;
        jsonSettings["projects"][projectName]["lib"] = lib;
        jsonSettings["projects"][projectName]["window"] = window;

        std::ofstream settingsFileWrite(configFilePath);
        settingsFileWrite << std::setw(4) << jsonSettings;
        settingsFileWrite.close();

        std::cout << SUCCESS_COLOR "Project (" + projectName + ") successfully added to settings.json\n" RESET_COLOR;

        if (startup) CHECK_FOR_ERROR(EditProperties(repositoryName, projectName, std::vector<std::string>(), true, false, false, false, false))

        return 0;
    }
    int CreateProjectSrc(std::string const& repositoryName, std::string const& projectName, bool pch, bool lib, bool window)
    {
        return 0;
    }
}
