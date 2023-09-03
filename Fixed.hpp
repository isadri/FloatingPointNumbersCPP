#ifndef __FIXED_HPP__
#define  __FIXED_HPP__

#include <iostream>
#include <cmath>
#include "Fp.hpp"

#define FLT_EPSILON ((float)pow(2, -8))

using namespace	FP_REP;

class	Fixed {
public:
	Fixed();
	Fixed(int);
	Fixed(float);
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

	friend std::ostream&	operator<<(std::ostream&, const Fixed&);

	// get fixed-point value
	int		getRawBits() const;
	// set fixed-point value
	void	setRawBits(int const);
	// get float-point value
	float	toFloat() const;
	// get int value
	int		toInt() const;
	
	void	displayRepresentation();

	static Fixed&	min(Fixed&, Fixed&);
	static Fixed&	min(const Fixed&, const Fixed&);
	static Fixed&	max(Fixed&, Fixed&);
	static Fixed&	max(const Fixed&, const Fixed&);

	FP&		getFp();
	void	setFp(float);

private:
	FP		_fp;
	int		_value;
	enum	{ FRAC_BITS = 8, FRAC_OF_MULT = 16 };
};

#endif