#pragma once
#include "math.h"
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <vector>

void commandblock(const std::string& input_user)
{
	const std::string commandPrefix = "\\MtPlc(";
	if (input_user.starts_with(commandPrefix))
	{
		std::string argString = input_user.substr(commandPrefix.length());

		if (!argString.empty() && argString.back() == ')')
		{ argString.pop_back(); }

		std::replace(argString.begin(), argString.end(), ',', ' ');

		std::istringstream sst(argString);
		int a, b;
		std::string reset;
		if (sst >> a >> b && !(sst >> reset)){multiplication(a, b);}
		else{ std::cout << "Invalid arguments for multiplication command" << std::endl; }
	}
	else{ std::cout << "Invalid command" << std::endl; }
}