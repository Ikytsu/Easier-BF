#include "../include/ebf.hpp"

void generate_c_code(std::string code, std::vector<std::string> config, bool debug)
{
	int openloop_count = 0;
	int closeloop_count = 0;
	for(char character : code)
	{
		if(character == '[')
		{
			openloop_count++;
		}
		else if(character == ']')
		{
			closeloop_count++:
		}
	}
	if(openloop_count != closeloop_count)
	{
		std::cout << noclosedloop_error << std::endl;
	}
}
