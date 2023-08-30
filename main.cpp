#include "Fixed.hpp"
#include "Fp.hpp"
#include <ios>

int	main() {
	FP	f(12.4f);
	FP	s(2.6f);
	
	f.displayBinRepresentation();
	f.displaySinglePrecisionFormat();
	s.displayBinRepresentation();
	s.displaySinglePrecisionFormat();
	return 0;
}
