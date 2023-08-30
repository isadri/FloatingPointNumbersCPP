#include "Fixed.hpp"
#include "Fp.hpp"
#include <cmath>

Fixed::Fixed() : _fp(0), _value(0) {
}

Fixed::Fixed(int value) : _fp(value), _value(value << _fracBits) {
}

Fixed::Fixed(float value) 
	: _fp(value)
	, _value((int)(round(value * (1 << _fracBits))))
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
	return toFloat() > f.toFloat();
}

bool	Fixed::operator<(const Fixed& f) const {
	return !(*this >= f);
}

bool	Fixed::operator>=(const Fixed& f) const {
	return toFloat() >= f.toFloat();
}

bool	Fixed::operator<=(const Fixed& f) const {
	return toFloat() <= f.toFloat();
}

bool	Fixed::operator==(const Fixed& f) const {
	return fabs(toFloat() - f.toFloat()) < FLT_EPSILON;
}

bool	Fixed::operator!=(const Fixed& f) const {
	return !(*this == f);
}

Fixed	Fixed::operator+(const Fixed& f) {
	return Fixed(_value + f._value);
}

Fixed	Fixed::operator-(const Fixed& f) {
	return Fixed(_value - f._value);
}

Fixed	Fixed::operator*(const Fixed& f) {
	return (toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed& f) {
	return Fixed(toFloat() / f.toFloat());
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
	return min((Fixed&)f1, (Fixed&)f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	return (f1 > f2) ? f1 : f2;
}

Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	return max((Fixed&)f1, (Fixed&)f2);
}

int	Fixed::getRawBits() const {
	return _value;
}

void	Fixed::setRawBits(int const raw) {
	_value = raw;
}

float	Fixed::toFloat() const {
	return (float)_value / (1 << _fracBits);
}

int	Fixed::toInt() const {
	return _value >> _fracBits;
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
