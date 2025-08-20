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


#define PCH_H \
    "#ifndef PCH_H"                          "\n"\
    "#define PCH_H"                          "\n"\
    ""                                       "\n"\
    "#include <iostream>"                    "\n"\
    ""                                       "\n"\
    "#endif"

#define PCH_H_WINDOW \
    "#ifndef PCH_H"                          "\n"\
    "#define PCH_H"                          "\n"\
    ""                                       "\n"\
    "#include <windows.h>"                   "\n"\
    ""                                       "\n"\
    "#endif"

#define PCH_CPP \
    "#include \"pch.h\""                     "\n"\
    ""



#define MAIN_H \
    "#ifndef MAIN_H"                         "\n"\
    "#define MAIN_H"                         "\n"\
    ""                                       "\n"\
    ""                                       "\n"\
    ""                                       "\n"\
    "#endif"

#define MAIN_CPP \
    "#include <iostream>"                    "\n"\
    "#include \"main.h\""                    "\n"\
    ""                                       "\n"\
    "int main()"                             "\n"\
    "{"                                      "\n"\
    "    std::cout << \"Hello, World!\\n\";" "\n"\
    "    return 0;"                          "\n"\
    "}"

#define MAIN_CPP_PCH \
    "#include \"pch.h\""                     "\n"\
    "#include \"main.h\""                    "\n"\
    ""                                       "\n"\
    "int main()"                             "\n"\
    "{"                                      "\n"\
    "    std::cout << \"Hello, World!\\n\";" "\n"\
    "    return 0;"                          "\n"\
    "}"

#define MAIN_CPP_WINDOW \
    "#include <windows.h>"                                                                 "\n"\
    "#include \"main.h\""                                                                  "\n"\
    ""                                                                                     "\n"\
    "int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int cmdShow)" "\n"\
    "{"                                                                                    "\n"\
    "    return 0;"                                                                        "\n"\
    "}"

#define MAIN_CPP_PCH_WINDOW \
    "#include \"pch.h\""                                                                   "\n"\
    "#include \"main.h\""                                                                  "\n"\
    ""                                                                                     "\n"\
    "int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int cmdShow)" "\n"\
    "{"                                                                                    "\n"\
    "    return 0;"                                                                        "\n"\
    "}"



#define VCPKG_CONFIGURATION \
    "{"                                                                                                    "\n"\
    "    \"default-registry\": {"                                                                          "\n"\
    "        \"baseline\": \"5a3e638f449206ac10f82f2171a21333004d7306\","                                  "\n"\
    "        \"kind\": \"git\","                                                                           "\n"\
    "        \"repository\": \"https://github.com/microsoft/vcpkg\""                                       "\n"\
    "    },"                                                                                               "\n"\
    "    \"registries\": ["                                                                                "\n"\
    "        {"                                                                                            "\n"\
    "            \"kind\": \"artifact\","                                                                      "\n"\
    "            \"location\": \"https://github.com/microsoft/vcpkg-ce-catalog/archive/refs/heads/main.zip\"," "\n"\
    "            \"name\": \"microsoft\""                                                                      "\n"\
    "        }"                                                                                            "\n"\
    "    ]"                                                                                                "\n"\
    "}"

#define VCPKG_JSON \
    "{"                                      "\n"\
    "    \"dependencies\": []"               "\n"\
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


