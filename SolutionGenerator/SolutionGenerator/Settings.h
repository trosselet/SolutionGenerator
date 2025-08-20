#pragma once

#define VERSION "1.0.0"

#define COLOR_STYLE(color) "\033[" color "m"
#define RESET_COLOR COLOR_STYLE("0")
#define ERROR_COLOR COLOR_STYLE("31")
#define SUCCESS_COLOR COLOR_STYLE("32")

#define CONFIG_SETTINGS( solutionName, solutionGuid ) (\
    "{"                                                    "\n"\
    "    \"version\": \"" VERSION "\","                    "\n"\
    "    \"solution_name\": \"" + ( solutionName ) + "\"," "\n"\
    "    \"solution_guid\": \"" + ( solutionGuid ) + "\"," "\n"\
    "    \"projects\": {},"                                "\n"\
    "    \"startup_project\": \"\""                        "\n"\
    "}")

#define PROJECT_CONFIG \
    "{"                                                    "\n"\
    "    \"guid\": \"\","                                  "\n"\
    "    \"pch\": false,"                                  "\n"\
    "    \"vcpkg\": false,"                                "\n"\
    "    \"lib\": false,"                                  "\n"\
    "    \"window\": false,"                               "\n"\
    /*"    \"filters\": ["                                   "\n"*/\
    /*"        "                                             "\n"*/\
    /*"    ],"                                               "\n"*/\
    "    \"dependencies\": [],"                            "\n"\
    "    \"dependents\": [],"                              "\n"\
    "    \"preprocessorDefinitions\": [],"                 "\n"\
    "    \"additionalIncludeDirectories\": [],"            "\n"\
    "    \"additionalLibraryDirectories\": [],"            "\n"\
    "    \"additionalDependencies\": []"                   "\n"\
    "}"


#define ERROR_IF( function, message ) \
    if ( function )\
    {\
        std::cout << ERROR_COLOR message RESET_COLOR;\
        return 1;\
    }

#define CHECK_FOR_ERROR( function ) \
    if ( SolutionGenerator::function != 0 )\
        return 1;


