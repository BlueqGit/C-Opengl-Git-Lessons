#include "Reader/Reader.h"

namespace FileReader
{
	std::string Reader::GetShaderFile(const char* file_name)
	{
		std::ifstream file(file_name);
		if (file.is_open())
		{
			std::string tmp;
			std::string line;
			while (std::getline(file, line))
			{
				tmp += line + "\n";
			}
			std::cout << "Shader:  " << file_name << "  -> success!" << std::endl;
			return tmp;
		}
		else
		{
			std::cout << "File can't be opened" << std::endl;
			return "null";
		}
	}
}