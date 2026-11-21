/*1. Принимает в конструкторе значение шаблонного типа Т.

2. Вычисляет и сохраняет внутри себя хэш этого значения(тип size_t) с помощью std::hash<T>.
	Само исходное значение хранить не нужно(как при проверке паролей).

3. Имеет метод bool verify(const T & candidate) const, 
	который вычисляет хэш от переданного значения и возвращает true, если ОН СОВпадает с эталОННЫМ.

4.Имеет метод size_t getHash() const, который возвращает сохраненный хэш.*/

#include <functional>
#include <iostream>
#include <string>

template <typename T>
class DataVerifier
{
private:
	size_t hashValue;
public:
	explicit DataVerifier(const T& value) : hashValue(std::hash<T>{}(value)) {}

	~DataVerifier() = default;

	bool verify(const T& candidate) const
	{
		return std::hash<T>{}(candidate) == hashValue;
	}

	size_t getHash() const { return hashValue; }

};
