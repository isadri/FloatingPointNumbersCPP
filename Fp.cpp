#include "Fp.hpp"
#include <cstdlib>

FP::FP(float number) : _fpValue({number}) {
}

FP::FP(int number) : _fpValue({float(number)}) {
}

FP::FP(const char* number) : _fpValue({(float)atof(number)}) {
}

FP::FP(const FP& f) {
}

FP&	FP::operator=(const FP& f) {
	_fpValue = f._fpValue;
	_memBits = f._memBits;
	return *this;
}

void	FP::displayBinRepresentation() {
	int	i = 0;

	for (int i = sizeof(float) - 1; i >= 0; i--) {
		for (int j = 0; j < BYTE_SIZE; j++) {
			_memBits[i] = (128 & _fpValue.c[i]) ? '1' : '0';
			std::cout << _memBits[i++]; 
			_fpValue.c[i] <<= 1;
		}
	}
}

void	FP::displaySinglePrecisionFormat() {
	int	i = 0;

	std::cout << "- 1-Bit Sign: " << _memBits[i++] << '\n';
	std::cout << "- 8-Bit Exponent: ";
	for (int j = 0; j < EXP_SIZE; j++)
		std::cout << _memBits[j + i];
	std::cout << "\n- 23-Bit Significand Fraction: ";
	for (int j = 0; j < FRACT_SIZE; j++)
		std::cout << _memBits[j + i];
	std::cout << '\n';
}
