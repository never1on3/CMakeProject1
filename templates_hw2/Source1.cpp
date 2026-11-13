#include <iostream>
#include <string>
// ============================================================
// ЗАДАЧА 1 (шаблон с одним типом): минимум из двух
// ============================================================
// Напишите шаблонную функцию minOf, которая принимает два
// значения одного типа T и возвращает меньшее из них.
//
// Пример: minOf(4, 5) -> 4
// TODO: напишите здесь шаблон minOf
template <typename T1, typename T2>
auto minOf(T1 a, T2 b) ->decltype(a < b ? a : b)
{
	return a < b ? a : b;
}

// ============================================================
// ЗАДАЧА 2 (шаблон с одним типом): сумма элементов массива
// ============================================================
// Напишите шаблонную функцию arraySum, которая принимает
// массив по ссылке и возвращает сумму всех элементов.
// Размер массива N — нетипизированный параметр шаблона.
// Пример: int arr[] = {1, 2, 3, 4}; arraySum(arr) -> 10
// Подсказка: template<typename T, size_t N>
// TODO: напишите здесь шаблон arraySum
template <typename T, size_t N>
T arraySum(const T(&data)[N])
{
	T sum{ 0 };
	for (const auto& item : data) { sum += item; }
	return sum;
}
// ============================================================
// ЗАДАЧА 3 (шаблон с двумя типами): вывести пару
// ============================================================
// Напишите шаблонную функцию printPair, которая принимает
// два значения РАЗНЫХ типов и выводит их в формате:
// "<первое> - <второе>"
// Пример: printPair(42, std::string("ответ")) -> "42 - ответ"
// Подсказка: template<typename T, typename K>
// TODO: напишите здесь шаблон printPair
template <typename T1, typename T2>
void printPair(T1 a, T2 b)
{
	std::cout << a << '-' << b << std::endl;
}
// ============================================================
// ЗАДАЧА 4 (шаблон с тремя и более типами): тройка
// ============================================================
// Напишите шаблонную функцию makeTriple, которая принимает
// ТРИ значения РАЗНЫХ типов и выводит их в формате:
// "[<первое>, <второе>, <третье>]"
//
// Пример: makeTriple(1, 2.5, std::string("три"))
//         -> "[1, 2.5, три]"
//
// Подсказка: template<typename T, typename K, typename V>
// TODO: напишите здесь шаблон makeTriple
template <typename T1, typename T2, typename STR>
void makeTriple(T1 a, T2 b, STR s)
{
	std::cout << '[' << a << ", " << b << ", " << s << ']' << std::endl;
}
// ============================================================
// ЗАДАЧА 5 (шаблон + указатель): найти максимум по указателям
// ============================================================
// Напишите шаблонную функцию maxPtr, которая принимает
// два указателя const T* и возвращает указатель на тот,
// по которому лежит большее значение.
// Если один из указателей nullptr — верните другой.
// Если оба nullptr — верните nullptr.
//
// Пример: int a = 3, b = 7; *maxPtr(&a, &b) -> 7
// TODO: напишите здесь шаблон maxPtr
template <typename T>
const T* maxPtr(const T* a, const T* b)
{
	if (a == nullptr) return b;
	if (b == nullptr) return a;
	return (*a > *b) ? a : b;
}
// ============================================================
// main — НЕ МЕНЯЙТЕ
// ============================================================
int main() {
	// Задача 1
	std::cout << "=== Задача 1: minOf ===" << std::endl;
	std::cout << "min(4, 5) = " << minOf(4, 5) << std::endl;
	std::cout << "min(3.4, 2.3) = " << minOf(3.4, 2.3) << std::endl;
		std::cout << "min(\"apple\", \"banana\") = "
		<< minOf(std::string("apple"), std::string("banana")) <<
		std::endl; // apple
	// Задача 2
	std::cout << "\n=== Задача 2: arraySum ===" << std::endl;
	int intArr[] = { 1, 2, 3, 4, 5 };
	double doubleArr[] = { 1.5, 2.5, 3.0 };
	std::cout << "int sum: " << arraySum(intArr) << std::endl;
		std::cout << "double sum: " << arraySum(doubleArr) << std::endl;
	// Задача 3
	std::cout << "\n=== Задача 3: printPair ===" << std::endl;
	printPair(42, std::string("ответ"));
	printPair(3.14, 100);
	// Задача 4
	std::cout << "\n=== Задача 4: makeTriple ===" << std::endl;
	makeTriple(1, 2.5, std::string("три")); // [1, 2.5, три]
	makeTriple(std::string("x"), 42, 3.14); // [x, 42, 3.14]
	// Задача 5
	std::cout << "\n=== Задача 5: maxPtr ===" << std::endl;
	int a = 3, b = 7;
	std::cout << "*maxPtr(&a, &b) = " << *maxPtr(&a, &b) << std::endl;
	// 7
	std::cout << "*maxPtr(&a, nullptr) = " << *maxPtr<int>(&a, nullptr) <<
		std::endl; // 3
	std::cout << "maxPtr(nullptr, nullptr) = "
		<< (maxPtr<int>(nullptr, nullptr) == nullptr ? "nullptr" : "неnullptr") << std::endl; // nullptr
	return 0;
}