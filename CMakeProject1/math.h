#pragma once
#include <iostream>
void printH(int a){std::cout << a;}
void quad(int a){std::cout << a * a;}
void division(int a, int b)
{
	if (b != 0){std::cout << a / b;}
	else{std::cout << "Error: Division by zero!";}
}
void multiplication(int a, int b){std::cout << a * b;}
void addition(int a, int b){std::cout << a + b;}
void subtraction(int a, int b){std::cout << a - b;}