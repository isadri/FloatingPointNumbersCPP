#ifndef __FP_HPP__
#define __FP_HPP__

#include <iostream>
#include <optional>
#include <ostream>
#include <string.h>

namespace	FP_REP {

	typedef union	{
		float			value;
		unsigned char	c[sizeof(float)];
	}	FloatNbr;

	class	FP {
	public:
		FP(float);
		FP(int);
		FP(const char*);
		FP(const FP&);
		~FP() = default;

		FP&	operator=(const FP&);

		FP	operator+(const FP&) const;
		FP	operator-(const FP&) const;
		FP	operator*(const FP&) const;
		FP	operator/(const FP&) const;

		void	displayBinRepresentation();
		void	displaySinglePrecisionFormat();

		float	getFpValue() const;

		friend std::ostream&	operator<<(std::ostream&, const FP&);

	private:
		FloatNbr	_fpValue;
		enum		{
			FORMAT_SIZE = 32, BYTE_SIZE = 8, EXP_SIZE = 8, FRACT_SIZE = 23
		};
		char		_memBits[FORMAT_SIZE];

		void	fillMemBits();
	};

	unsigned long long	operator"" _b(unsigned long long);
}

#endif