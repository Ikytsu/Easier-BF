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
							//std::cout << get_end_string(i + 1, lineconfig) << std::endl; 			
						}
						else if(temp_string == "substract")
						{
							
						}
						else if(temp_string == "move_next")
						{
							
						}
						else if(temp_string == "move_previous")
						{
							
						}
						else if(temp_string == "output")
						{
							
						}
						else if(temp_string == "input")
						{
							
						}
						else if(temp_string == "output_type_switcher")
						{
							
						}
						else if(temp_string == "assign_char")
						{
							
						}
						else if(temp_string == "table_create")
						{
							
						}
						else if(temp_string == "table_gochild")
						{
							
						}
						else if(temp_string == "table_goparent")
						{
							
						}
						else if(temp_string == "table_delete")
						{
							
						}
						else if(temp_string == "table_remove")
						{
							
						}
						else if(temp_string == "add_subtract_value")
						{
							
						}
						else if(temp_string == "move_value")
						{
							
						}
						else if(temp_string == "output_type_switcher_default")
						{
							
						}
						else if(temp_string == "table_create_value")
						{
							
						}
						else if(temp_string == "table_remove_value")
						{
							
						}
						else
						{
							
						}
					}
					if(!falledintocolon)
					{
						
					}
			}
			}
	return config_infos;
}	
}
}

