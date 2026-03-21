#pragma once
#include <iostream>
#include <string>
#include <fstream>

namespace FileReader
{
	class Reader
	{
	public:
		std::string GetShaderFile(const char* file_name);
	};
}