#include "../include/ebf.hpp"

void start_compilation(int argc, char * argv[])
{
	int i = 1;
	std::string File_name_string;;
	char * File_name_charpointer = nullptr;
	bool debug = false;
	for(; i < argc ; i++)
	{
		if(static_cast<std::string>(argv[i]) == "-version")
		{
			std::cout << version_output << std::endl;
		}
		else if(static_cast<std::string>(argv[i]) == "-debug")
		{
			if(!debug)
			{
				debug = true;
			}
			else
			{
				std::cout << multiplearg_warning << std::endl;
			}
		}
		else if(static_cast<std::string>(argv[i]) == "-file")
		{
			if(File_name_charpointer == nullptr)
			{
				if(argv[i + 1] != nullptr)
				{
					File_name_string = static_cast<std::string>(argv[i + 1]);
					File_name_charpointer = argv[i + 1];
					i++;
				}
				else
				{
					throw std::runtime_error(filenullptr_error);
				}
			}
			else
			{
				std::cout << multiplearg_warning << std::endl;
				i++;
			}
		}
		else
		{
			std::cout << unknownarg_warning << std::endl;
		}
	}
	

	if(File_name_charpointer != nullptr)
	{
		if(debug)std::cout << debug_check_gcc_message << std::endl;

		int gccnotinstalled = std::system("gcc --version > /dev/null 2>&1");

		if(gccnotinstalled) //gcc not installed
		{
			throw std::runtime_error(gccnotinstalled_error);
		}
	
		if(debug)std::cout << "-------------------------" << std::endl;
		if(debug)std::cout << debug_start_compilation_message << " " << File_name_string << std::endl;

		std::filesystem::path pathObj(File_name_charpointer);
		
		std::string extension = pathObj.extension().string();
		
		if(extension != ".ebf" && extension != ".bf" && extension != ".b" && extension != ".nbf") //not correct extension
		{
			throw std::runtime_error(incorrectextenstion_error);
		}
		
		if(!std::filesystem::exists(File_name_string)) //file doesn't exist 
		{
			throw std::runtime_error(unexistingfile_error);
		}
		std::ifstream t(File_name_string);
		std::string code((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

		if(debug)std::cout << "-------------------------" << std::endl;
		if(debug)std::cout << debug_check_config_file_message << std::endl;
		
		std::vector<std::string> config_loaded = load_config(debug);

		if(debug)std::cout << "-------------------------" << std::endl;
		if(debug)std::cout << debug_generating_c_code_message << std::endl;

		generate_c_code(code, config_loaded, debug);

		if(debug)std::cout << "-------------------------" << std::endl;
		if(debug)std::cout << debug_compiling_c_code_message << std::endl;
	}
	else
	{
		if(debug)std::cout << debug_no_indicated_file_message << std::endl;
	}
}

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
    	std::cout << help_output << std::endl;
    }
    else
    {
    	try
    	{
    		start_compilation(argc, argv);
    	}
    	catch(const std::runtime_error& e)
    	{
    		std::cout << e.what() << std::endl;
    	}
    }
    return 0;
}
