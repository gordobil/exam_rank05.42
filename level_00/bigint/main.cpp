
#include "bigint.hpp"

int	main(){
	bigint	a(123), b(987654), c(3), d(2);

	std::cout << a << "  " << b << "  " << c << "  " << d << std::endl << std::endl;

/* 	std::cout << " - " << (a + c) << std::endl;
	std::cout << " - " << (b + 346) << std::endl;
	std::cout << " - " << (7 + c) << std::endl;*/
	std::cout << " - " << (c += d) << std::endl;
	std::cout << " - " << (c += 5) << std::endl;
}