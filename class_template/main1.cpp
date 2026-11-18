#include <iostream>
#include <string>
#include "DataVerifier.h" // подключаем свой header
int main() {
	std::cout << "=== DataVerifier<std::string> ===" << std::endl;
	DataVerifier<std::string> v("secret123");
	std::cout << "verify(\"secret123\") = " << v.verify("secret123") << std::endl; // 1
	std::cout << "verify(\"wrong\") = " << v.verify("wrong") << std::endl; // 0
	std::cout << "getHash() = " << v.getHash() << std::endl; 
	// число
	std::cout << "\n=== DataVerifier<int> ===" << std::endl;
	DataVerifier<int> vi(1234);
	std::cout << "vi.verify(1234) = " << vi.verify(1234) << std::endl; // 1
	std::cout << "vi.verify(9999) = " << vi.verify(9999) << std::endl; // 0
	std::cout << "vi.getHash() = " << vi.getHash() << std::endl;
	//число
	std::cout << "\n=== DataVerifier<double> ===" << std::endl;
	DataVerifier<double> vd(3.14);
	std::cout << "vd.verify(3.14) = " << vd.verify(3.14) << std::endl; // 1
	std::cout << "vd.verify(2.71) = " << vd.verify(2.71) << std::endl; // 0
	std::cout << "vd.getHash() = " << vd.getHash() << std::endl;
	//число
	return 0;
}
