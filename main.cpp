#include "Fixed.hpp"
#include "Fp.hpp"
#include <ios>

int	main() {
	FP	f(12.4f);
	FP	s(2.6f);
	
	f.displayBinRepresentation();
	s.displayBinRepresentation();
	return 0;
}
