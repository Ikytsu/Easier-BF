#ifndef EBF_H
#define EBF_H

#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

//General output
static std::string help_output = "-file [filename] : specify a file for compilation"
    	"\n-debug : indicate all steps of the compilation"
    	"\n-version : indicate version of the compiler";
static std::string version_output = "work in progress :)";

//Debugs 
static std::string debug_start_compilation_message = "starting compilation of";
static std::string debug_optimizing_code_message = "optimizing the ebf code...";
static std::string debug_no_indicated_file_message = "no indicated file, terminating the process";
static std::string debug_check_gcc_message = "checking if gcc is installed...";
static std::string debug_check_config_file_message = "checking the config file...";
static std::string debug_check_config_file_notexist_message = "no config file found, creating one...";
static std::string debug_generating_c_code_message = "generating the C equivalent code...";
static std::string debug_compiling_c_code_message = "compiling the C code...";
//Warnings
static std::string multiplearg_warning = "Warning: an argument has been put multiple times, ignoring it and the next if it's -file";
static std::string unknownarg_warning = "Warning: an unknown arg has been put, ignoring it"; 
static std::string nosemicolon_warning = "Warning: no semicolon, ignoring";
static std::string unknownconfig_warning = "Warning: an unknown config has been detected, read the documentation to correct this";
static std::string incorrectconfigvalue_warning = "Warning: an incorrect config value has been detected, read the documentation to correct this";
//Errors
static std::string filenullptr_error = "Error: nothing after -file ";
static std::string unexistingfile_error = "Error: The file doesn't exists";
static std::string incorrectextenstion_error = "Error: Incorrect extension, the correct ones are .bf, .ebf, .b and .nbf";
static std::string gccnotinstalled_error = "Error: gcc is needed for the compilation, you need to install it and make it accessible on your PATH/command";

//Functions definitions
std::vector<std::string> load_config(bool debug);

#endif
