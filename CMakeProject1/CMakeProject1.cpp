// CMakeProject1.cpp: определяет точку входа для приложения.
//

#include "CMakeProject1.h"
#include <iostream>
#include "math.h"
#include "culc.h"

int main()
{
	std::string input_user;
	std::cout << "Enter command: ";
	std::getline(std::cin, input_user);
	commandblock(input_user);

	return 0;
}
