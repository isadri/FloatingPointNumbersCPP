#include "Fixed.hpp"

int	main() {
	Fixed	f(12.3f);
	
	std::cout << f.getRawBits() << '\n';
	std::cout << f.getFp() << '\n';
	return 0;
}
