#ifndef __FIXED_HPP__
#define  __FIXED_HPP__

#include <iostream>
#include <cmath>
#include "Fp.hpp"

#define FLT_EPSILON ((float)pow(2, -8))

class	Fixed {
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	~Fixed();

	Fixed&	operator=(const Fixed&);

	bool	operator>(const Fixed&) const;
	bool	operator<(const Fixed&) const;
	bool	operator>=(const Fixed&) const;
	bool	operator<=(const Fixed&) const;
	bool	operator==(const Fixed&) const;
	bool	operator!=(const Fixed&) const;

	Fixed	operator+(const Fixed&);
	Fixed	operator-(const Fixed&);
	Fixed	operator*(const Fixed&);
	Fixed	operator/(const Fixed&);
	Fixed&	operator--();
	Fixed&	operator++();
	Fixed	operator--(int);
	Fixed	operator++(int);

	int		getRawBits() const;
	void	setRawBits(int const);
	float	toFloat() const;
	int		toInt() const;

	static Fixed&	min(Fixed&, Fixed&);
	static Fixed&	min(const Fixed&, const Fixed&);
	static Fixed&	max(Fixed&, Fixed&);
	static Fixed&	max(const Fixed&, const Fixed&);

private:
	FP					_fp;
	int					_value;
	static const int	_fracBits = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif