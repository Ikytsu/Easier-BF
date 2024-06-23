#include "../include/ebf.hpp"

/*/ How would look like the vector as dict for config management (change syntax with the config) 

std::map<std::string, int> my_map = {
    {"add", 1},
    {"substract", 2},
    {"move_next", 3},
    {"move_previous", 4},
    {"output", 5},
    {"input", 6},
    {"output_type_switcher", 7},
    {"assign_char", 8},
    {"table_create", 9},
    {"table_gochild", 10},
    {"table_goparent", 11},
    {"table_delete", 12},
    {"table_remove", 13},

    {add_substract_value, 14},
    {move_value, 15},
	{output_type_switcher_default, 16},
	{table_create_value, 17},
	{table_remove_value, 18},

};/*/

std::string get_end_string(int index, const std::string& str)
{
    std::string endstring = "";
    for(int i = index; i < str.size(); i++)
    {
        if(str[i] != ' ')
        {
            endstring += str[i];
        }
    }
    return endstring;
}

bool isint(std::string number)
{
	try 
	{
	  std::stoi(number);
	  for(char character : number)
	  {
	  	if(character == '.')
	  	{
	  		return false;
	  	}
	  }
	  return true;
	}
	catch(const std::exception& err) 
	{
	  return false;
	} 
}

std::vector<std::string> load_config(bool debug)
{
	std::vector<std::string> config_infos = {"+", "-", ">", "<", ".", ",", "$", "#", "\\", "*", "&", "/", "%", "1", "1", "ASCII", "1", "1"};

	if(!std::filesystem::exists("config.txt"))
	{
		std::ofstream config_file("config.txt");
		config_file << "";
		config_file.close();
	}
	else
	{
		std::ifstream t("config.txt");
		std::string textinconfigfile((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());
		if(textinconfigfile != "")
		{
			std::vector<std::string> text_per_line;
			std::string temp_string = "";
			int i = 0;
			for(; i < textinconfigfile.size() ; i++)
			{
				if(textinconfigfile[i] != '\n' && i < textinconfigfile.size() - 1)
				{
					temp_string += textinconfigfile[i];
				}
				else
				{
					if(temp_string != "")
					{
						text_per_line.push_back(temp_string);
					}
					temp_string = "";
				}
			}
			temp_string = "";
			for(std::string lineconfig : text_per_line)
			{
				int i = 0;
				for(; i < lineconfig.size() ; i++)
				{
					bool falledintocolon = false;
					if(lineconfig[i] != ':')
					{
						if(lineconfig[i] != ' ')
						{
							temp_string += lineconfig[i];	
						}
					}
					else
					{
						falledintocolon = true;
						if(temp_string == "add")
						{
							config_infos[0] = get_end_string(i + 1, lineconfig);		
						}
						else if(temp_string == "substract")
						{
							config_infos[1] = get_end_string(i + 1, lineconfig);	
						}
						else if(temp_string == "move_next")
						{
							config_infos[2] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "move_previous")
						{
							config_infos[3] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "output")
						{
							config_infos[4] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "input")
						{
							config_infos[5] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "output_type_switcher")
						{
							config_infos[6] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "assign_char")
						{
							config_infos[7] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "table_create")
						{
							config_infos[8] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "table_gochild")
						{
							config_infos[9] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "table_goparent")
						{
							config_infos[10] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "table_delete")
						{
							config_infos[11] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "table_remove")
						{
							config_infos[12] = get_end_string(i + 1, lineconfig);
						}
						else if(temp_string == "add_subtract_value")
						{
							std::string info = get_end_string(i + 1, lineconfig);
							if(isint(info))
							{
								config_infos[13] = info;
							}
							else
							{
								std::cout << incorrectconfigvalue_warning << ": \"" + lineconfig + "\"" << std::endl;
							}						
						}
						else if(temp_string == "move_value")
						{
							std::string info = get_end_string(i + 1, lineconfig);
							if(isint(info))
							{
								config_infos[14] = info;
							}
							else
							{
								std::cout << incorrectconfigvalue_warning << ": \"" + lineconfig + "\"" << std::endl;
							}	
						}
						else if(temp_string == "output_type_switcher_default")
						{
							std::string info = get_end_string(i + 1, lineconfig);
							if(info == "ASCII" || info == "INT")
							{
								config_infos[15] = info;
							}
							else
							{
								std::cout << incorrectconfigvalue_warning << ": \"" + lineconfig + "\"" << std::endl;
							}
						}
						else if(temp_string == "table_create_value")
						{
							std::string info = get_end_string(i + 1, lineconfig);
							if(isint(info))
							{
								config_infos[16] = info;
							}
							else
							{
								std::cout << incorrectconfigvalue_warning << ": \"" + lineconfig + "\"" << std::endl;
							}	
						}
						else if(temp_string == "table_remove_value")
						{
							std::string info = get_end_string(i + 1, lineconfig);
							if(isint(info))
							{
								config_infos[17] = info;
							}
							else
							{
								std::cout << incorrectconfigvalue_warning << ": \"" + lineconfig + "\"" << std::endl;
							}	
						}
						else
						{
							std::cout << unknownconfig_warning << ": \"" + lineconfig + "\"" << std::endl;
						}
						break;
					}
					if(!falledintocolon && i == lineconfig.size() - 1)
					{
						std::cout << nosemicolon_warning << ": \"" + lineconfig + "\"" << std::endl;				
					}
				}
			}
		}		
	}
	if(debug)
	{
		std::cout << "config result:" << std::endl;
		int i = 0;
		for(; i < config_infos.size() ; i++)
		{
			if(i == 0)
			{
				std::cout << "add: ";
			}
			else if(i == 1)
			{
				std::cout << "substract: ";
			}
			else if(i == 2)
			{
				std::cout << "move_next: ";
			}
			else if(i == 3)
			{
				std::cout << "move_previous: ";
			}
			else if(i == 4)
			{
				std::cout << "output: ";
			}
			else if(i == 5)
			{
				std::cout << "input: ";
			}
			else if(i == 6)
			{
				std::cout << "output_type_switcher: ";
			}
			else if(i == 7)
			{
				std::cout << "assign_char: ";
			}
			else if(i == 8)
			{
				std::cout << "table_create: ";
			}
			else if(i == 9)
			{
				std::cout << "table_gochild: ";
			}
			else if(i == 10)
			{
				std::cout << "table_goparent: ";
			}
			else if(i == 11)
			{
				std::cout << "table_delete: ";
			}
			else if(i == 12)
			{
				std::cout << "table_remove: ";
			}
			else if(i == 13)
			{
				std::cout << "add_subtract_value: ";
			}
			else if(i == 14)
			{
				std::cout << "move_value: ";
			}
			else if(i == 15)
			{
				std::cout << "output_type_switcher_default: ";
			}
			else if(i == 16)
			{
				std::cout << "table_create_value: ";
			}
			else if(i == 17)
			{
				std::cout << "table_remove_value: ";
			}
			std::cout << config_infos[i] << std::endl;
		}
	}
	return config_infos;
}

