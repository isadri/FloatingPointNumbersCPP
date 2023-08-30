#include "Fp.hpp"
#include <cstdlib>
#include <ostream>

FP::FP(float number) : _fpValue({number}) {
	fillMemBits();
}

FP::FP(int number) : _fpValue({float(number)}) {
	fillMemBits();
}

FP::FP(const char* number) : _fpValue({(float)atof(number)}) {
	fillMemBits();
}

FP::FP(const FP& f) {
	fillMemBits();
}

FP&	FP::operator=(const FP& f) {
	_fpValue = f._fpValue;
	_memBits = f._memBits;
	fillMemBits();
	return *this;
}

void	FP::fillMemBits() {
	unsigned char*	c = _fpValue.c;
	int				k = 0;

	for (int i = sizeof(float) - 1; i >= 0; i--) {
		for (int j = 0; j < BYTE_SIZE; j++) {
			_memBits[k++] = (128 & c[i]) ? '1' : '0';
			c[i] <<= 1;
		}
	}
}

void	FP::displayBinRepresentation() {
	for (int i = 0; i < FORMAT_SZIE; i++) {
		std::cout << _memBits[i]; 
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

float	FP::getFpValue() const {
	return _fpValue.value;
}

std::ostream&	operator<<(std::ostream& os, const FP& f) {
	os << f._fpValue.value;
	return os;
}
