#include <iostream>
#include <string>

template <typename T1, typename T2>
auto minOf(T1 a, T2 b) ->decltype(a < b ? a : b)
{
	return a < b ? a : b;
}

template <typename T, size_t N>
T arraySum(const T(&data)[N])
{
	T sum{ 0 };
	for (const auto& item : data) { sum += item; }
	return sum;
}

template <typename T1, typename T2>
void printPair(T1 a, T2 b)
{
	std::cout << a << '-' << b << std::endl;
}

template <typename T1, typename T2, typename STR>
void makeTriple(T1 a, T2 b, STR s)
{
	std::cout << a << ", " << b << ", " << s << std::endl;
}

template <typename T>
const T* maxPtr(const T* a, const T* b)
{
	if (a == nullptr) return b;
	if (b == nullptr) return a;
	return (*a > *b) ? a : b;
}

template <typename T>
class HashCheck
{
private:
	T id{};
	std::string name{};
public:
	HashCheck(T id, std::string name) : id{id}, name{ name } {}
	~HashCheck() {}

	void printInfo() const
	{
		std::cout << id << ' ' << name << std::endl;
	}
};

// ============================================================
// main — НЕ МЕНЯЙТЕ
// ============================================================
int main() {

	HashCheck hashCheck(37223, "dfbjd");
	hashCheck.printInfo();

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