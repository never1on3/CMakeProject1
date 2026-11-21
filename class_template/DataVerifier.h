#pragma once
#ifndef DATAVERIFIER_H
#define DATAVERIFIER_H
#include <functional> 
#include <cstddef>

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

#endif