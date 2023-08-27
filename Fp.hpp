#ifndef __FP_HPP__
#define __FP_HPP__

#include <iostream>
#include <string.h>

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

	void	displayBinRepresentation();
	void	displaySinglePrecisionFormat();

private:
	FloatNbr	_fpValue;
	enum		{
		BYTE_SIZE = 8, EXP_SIZE = 8, FRACT_SIZE = 23
	};
	std::string		_memBits;
};

#endif