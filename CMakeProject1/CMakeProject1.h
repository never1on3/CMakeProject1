// CMakeProject1.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>

void helpWindow()
{
	std::cout << "Available commands:\n";
	std::cout << "\\MtPlc(a, b) - Multiply a and b\n";
	std::cout << "\\MtAdd(a, b) - Add a and b\n";
	std::cout << "\\MtSub(a, b) - Subtract b from a\n";
	std::cout << "\\MtDiv(a, b) - Divide a by b\n";
}

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
bool divide(int a, int b, double& result);

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
