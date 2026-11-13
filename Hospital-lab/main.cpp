#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <format>

enum class Department 
{
	Therapy,
	Surgery,
	Cardiology,
	Unknown
};
enum class PatientState 
{
	InQueue,// В очереди
	InTreatment, // Лечится
	Discharged // Выписан
};

std::string stateToString(PatientState s)
{
	switch (s)
	{
	case PatientState::InQueue: return "IN line";
	case PatientState::InTreatment: return "is being treated";
	case PatientState::Discharged: return "Discharged";
	default: return "Unknown";
	}
}

std::string departmentToString(Department d) 
{
	switch (d) 
	{
	case Department::Therapy: return "Therapy";
	case Department::Surgery: return "Surgery";
	case Department::Cardiology: return "Cardiology";
	default: return "Unknown";
	}
}

class Patient 
{
private:
	std::string name;
	int age;
	Department department;
	PatientState state;
public:
	Patient(std::string name, int age, Department dept) : name(name), age(age), department(dept), state(PatientState::InQueue) {}
	
	std::string getName() const;
	int getAge() const;
	Department getDepartment() const;
	PatientState getState() const;

	void setAge(int age)
	{
		if (age >= 0 && age <= 120){ this->age = age; }
	}
	void setState(PatientState s) 
	{
		state = s;
		PatientState oldState = state;
	}
	
	void updateState(Patient& patient)
	{
		patient.setState(PatientState::InTreatment);
	}

	virtual void printInfo()
	{
		std::cout << "Name: " << name << ' ';
		std::cout << "Age: " << age << ' ';
		std::cout << "Department: " << departmentToString(department) << ' ';
	}

	virtual std::string getDescription() const
	{
		std::string description = "Name: " + name + '\n'
			+ "Age: " + std::to_string(age) + '\n'
			+ "Department: " + departmentToString(department) + '\n'
			+ "State: " + stateToString(state);
		return description;
	}
	virtual ~Patient() = default;
};

class ChildPatient : public Patient 
{
private:
	std::string parentName;
public:
	ChildPatient(std::string name, int age, Department dept, std::string parentName) : Patient(name, age, dept), parentName(parentName) {}

	std::string getDescription() const override
	{
		std::string descript = Patient::getDescription()
			+ " | Parent's Name: " + parentName;
		return descript;	
	}
	void printInfo() override
	{
		Patient::printInfo();
		std::cout << "Parent's Name: " << parentName << std::endl;
	}
};

template<typename T>
T addact(T a, T b) { return a + b; }

template<typename T1, typename T2>
void my_swap(T1& a, T2& b) { T1 temp = a; a = b; b = temp; }

template <typename K, typename U>
void cash(K kash, U user, int& overstake)
{
	std::cout << "Account: " << user << " has " << kash << " money" << std::endl;
	K overstake += kash;
}

template <typename T, typename U>
T findElement(std::vector<T&>, U size)
{
	for (auto const t : T)
	{
		if (t == 5)
		{
			std::cout << ' '<<t << '\n';
			return t;
		}
	}
}

int main()
{
	std::cout << addact(2, 3) << ' ' 
		<< addact(std::string("sos"), std::string("all")) << ' ' 
			<< addact(2.3232, 56.434) << "\n";
	int a = 20;
	double b = 45.90;
	int b2 = 45;
	my_swap(a, b);
	std::cout << a << ' ' << b << '\n';
	
	setlocale(LC_ALL, "RUSSIAN");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	ChildPatient child("Ivan", 10, Department::Therapy, "masha");
	ChildPatient child2("Petya", 12, Department::Surgery, "Olya");
	Patient patient("Vasya", 30, Department::Cardiology);

	child.printInfo();
	child2.printInfo();
	std::cout << patient.getDescription() << std::endl;

}