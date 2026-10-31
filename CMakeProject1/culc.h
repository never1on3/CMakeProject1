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
    static const std::unordered_map<std::string, std::function<void(int, int)>> commandMap =
    {
        { "\\MtPlc", multiplication },
        { "\\MtAdd", addition },
        { "\\MtSub", subtraction },
        { "\\MtDiv", division }
    };

    size_t openParenPos = input_user.find('(');
    size_t closeParenPos = input_user.find(')', openParenPos);
    if (openParenPos == std::string::npos || closeParenPos == std::string::npos)
    {
        std::cout << "Invalid command syntax" << std::endl;
        return;
    }

    std::string commandName = input_user.substr(0, openParenPos);
    std::string argString = input_user.substr(openParenPos + 1, closeParenPos - openParenPos - 1);

    auto trim = [](std::string& str)
    {
        const char* wStr = " \t\r\n";
	    str.erase(0, str.find_first_not_of(wStr));
	    str.erase(str.find_last_not_of(wStr) + 1);
    };
	trim(commandName);

    auto it = commandMap.find(commandName);
    if (it == commandMap.end())
    {
        std::cout << "Invalid command" << std::endl;
        return;
    }

    std::replace(argString.begin(), argString.end(), ',', ' ');
    std::istringstream sst(argString);
    int a, b;
    if (sst >> a >> b)
    {
        it->second(a, b);
    }
    else{ std::cout << "Invalid arguments" << std::endl; }
}