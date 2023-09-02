#include "Fixed.hpp"
#include "Fp.hpp"
#include <cmath>

Fixed::Fixed() : _fp(0), _value(0) {
}

Fixed::Fixed(int value) : _fp(value), _value(value << FRAC_BITS) {
}

Fixed::Fixed(float value) 
	: _fp(value)
	, _value((int)(round(value * (1 << FRAC_BITS))))
{
}

Fixed::Fixed(const Fixed& f) : _fp(f._fp), _value(f._value){
}

Fixed::~Fixed() {
}

Fixed&	Fixed::operator=(const Fixed& f) {
	_value = f._value;
	return *this;
}

bool	Fixed::operator>(const Fixed& f) const {
	return _value > f._value;
}

bool	Fixed::operator<(const Fixed& f) const {
	return !(*this >= f);
}

bool	Fixed::operator>=(const Fixed& f) const {
	return _value >= f._value;
}

bool	Fixed::operator<=(const Fixed& f) const {
	return _value <= f._value;
}

bool	Fixed::operator==(const Fixed& f) const {
	return _value == f._value;
}

bool	Fixed::operator!=(const Fixed& f) const {
	return !(*this == f);
}

Fixed	Fixed::operator+(const Fixed& f) {
	Fixed	n;

	n.setRawBits(_value + f._value);
	return n;
}

Fixed	Fixed::operator-(const Fixed& f) {
	Fixed	n;

	n.setRawBits(_value - f._value);
	return n;
}

Fixed	Fixed::operator*(const Fixed& f) {
	return Fixed((float)(_value * f._value) / (1 << FRAC_OF_MULT));
}

Fixed	Fixed::operator/(const Fixed& f) {
	return Fixed((float)_value / f._value);
}

Fixed&	Fixed::operator--() {
	*this = Fixed(toFloat() - FLT_EPSILON);
	return *this;
}

Fixed&	Fixed::operator++() {
	*this = Fixed(toFloat() + FLT_EPSILON);
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	old = *this;

	++*this;
	return old;
}

Fixed	Fixed::operator--(int) {
	Fixed	old = *this;

	--*this;
	return old;
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2) {
	return (f1 < f2) ? f1 : f2;
}

Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2) {
	return (Fixed&)((f1 < f2) ? f1 : f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	return (f1 > f2) ? f1 : f2;
}

Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	return (Fixed&)((f1 > f2) ? f1 : f2);
}

int	Fixed::getRawBits() const {
	return _value;
}

void	Fixed::setRawBits(int const raw) {
	_value = raw;
}

float	Fixed::toFloat() const {
	return (float)_value / (1 << FRAC_BITS);
}

int	Fixed::toInt() const {
	return _value >> FRAC_BITS;
}

FP&	Fixed::getFp() {
	return _fp;
}

void	Fixed::setFp(float f) {
	_fp = FP(f);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return os;
}
