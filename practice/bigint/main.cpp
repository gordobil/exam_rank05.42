
#include "bigint.hpp"

int	main(){
	bigint	a(123), b(987654), c(3);

	std::cout << a << "  " << b << "  " << c << std::endl;
	std::cout << (a << 2) << std::endl;
	std::cout << (a << c) << std::endl;
	std::cout << (b >> c) << std::endl;
	std::cout << (b >> 2) << std::endl;

	std::cout << (a < b) << std::endl;
//	std::cout << (a < 4) << std::endl;
}