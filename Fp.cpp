#include "Fp.hpp"
#include <cstdlib>
#include <ostream>

using namespace FP_REP;

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
	for (int i = 0; i < FORMAT_SIZE; i++)
		_memBits[i] = f._memBits[i];
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
	for (int i = 0; i < FORMAT_SIZE; i++) {
		std::cout << _memBits[i]; 
	}
	std::cout << '\n';
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

std::ostream&	FP_REP::operator<<(std::ostream& os, const FP& f) {
	os << f._fpValue.value;
	return os;
}

unsigned long long	FP_REP::operator""_b(unsigned long long bin) {
	long long	dec = 0;
	int			p = 0;

	while (bin) {
		dec += pow(2, p++) * (bin % 10);
		bin /= 10;
	}
	return dec;
}
