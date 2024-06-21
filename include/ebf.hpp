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

//General output
static std::string help_output = "-file [filename] : specify a file for compilation"
    	"\n-debug : indicate all steps of the compilation"
    	"\n-version : indicate version of the compiler";
static std::string version_output = "work in progress :)";
static std::string debug1_output = "starting compilation of";
static std::string debug2_output = "loading the syntax configuration file...";
static std::string debug3_output = "no indicated file, terminating the process";


//Warnings
static std::string multiplearg_warning = "Warning: an argument has been put multiple times, ignoring it and the next if it's -file";
static std::string unknownarg_warning = "Warning: an unknown arg has been put, ignoring it"; 

//Errors
static std::string filenullptr_error = "Error: nothing after -file ";
static std::string unexistingfile_error = "Error: The file doesn't exists";
static std::string incorrectextenstion_error = "Error: Incorrect extension, the correct ones are .bf, .ebf, .b and .nbf";

//Functions


#endif
