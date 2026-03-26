
#include "vect2.hpp"

int	main(){
	vect2	a(1, 2);
	vect2	b(3, 5);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a++ << std::endl;
	std::cout << ++a << std::endl;

	a[0] = 20;
	std::cout << a << std::endl;

	return (0);
}