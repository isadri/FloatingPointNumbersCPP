#include "Fixed.hpp"
#include "Fp.hpp"
#include <cstdlib>
#include <ios>
#include <iostream>

int	main() {
	Fixed	f(12.4f);
	Fixed	s(2);
	
	Fixed	m = f + s;
	std::cout << "f = " << f.getRawBits() << '\n';
	std::cout << "s = " << s.getRawBits() << '\n';
	std::cout << "m = " << m.getRawBits() << '\n';
	std::cout << "\nf + s = " << f + s << '\n';
	std::cout << "f - s = " << f - s << '\n';
	std::cout << "f * s = " << f * s << '\n';
	std::cout << "f / s = " << f / s << '\n';
	return 0;
}
