// CMakeProject1.cpp: определяет точку входа для приложения.
//

#include "CMakeProject1.h"
#include <iostream>
#include "math.h"
#include "culc.h"

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
bool divide(int a, int b, double& result) {
	if (b == 0) return false;
	result = static_cast<double>(a) / b;
	return true;
}

template <typename T1>
T1 addact(T1 a, T1 b) { return a + a; }

int main()
{
	std::cout << addact(1, 3) << ' ' << addact(2.323, 3.543) << ' '<<addact("dsdaw", "dasdwd");

	setlocale(LC_ALL, "RUSSIAN");
		int a, b;
		std::cout << "Введите два числа: ";
		std::cin >> a >> b;
		std::cout << "Сумма: " << add(a, b) << std::endl;
		std::cout << "Разность: " << subtract(a, b) << std::endl;
		std::cout << "Произведение: " << multiply(a, b) << std::endl;
		double q;
		if (divide(a, b, q))
			std::cout << "Частное: " << q << std::endl;
		else
			std::cout << "Деление на ноль!" << std::endl;

		std::cout << "Press any key to...\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();

	helpWindow();

	std::string input_user;
	std::cout << "Enter command: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
	std::getline(std::cin, input_user);
	commandblock(input_user);

	return 0;
}
