#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_SINGLE_FORMAT 32
#define SIZE_DOUBLE_FORMAT 64

typedef union {
	float			d;
	unsigned char	c[sizeof(float)];
}	fRep;

typedef union {
	double			d;
	unsigned char	c[sizeof(double)];
}	dRep;

void	displaySinglePrecisionFormat(char r[]) {
	printf("- 1-Bit Sign: %c\n", r[0]);
	printf("- 8-Bit Exponent: ");
	for (int i = 1; i < 9; i++)
		printf("%c", r[i]);
	printf("\n");
	printf("- 23-Bit Significand Fraction: ");
	for (int i = 9; i < 32; i++)
		printf("%c", r[i]);
	printf("\n");
}

void	displayDoublePrecisionFormat(char r[]) {
	printf("- 1-Bit Sign: %c\n", r[0]);
	printf("- 11-Bit Exponent: ");
	for (int i = 1; i < 12; i++)
		printf("%c", r[i]);
	printf("\n");
	printf("- 51-Bit Significand Fraction: ");
	for (int i = 9; i < 64; i++)
		printf("%c", r[i]);
	printf("\n");
}

void	displayBinaryFormat(char a, char **ptr) {
	char	c;

	for (int i = 0; i < 8; i++) {
		c = (128 & a) ? '1' : '0';
		printf("%c", c);
		(*ptr)[i] = c;
		a <<= 1;
	}
	*ptr += 8;
}

void	singlePrecision(char *number) {
	fRep	f;
	char	r[SIZE_SINGLE_FORMAT];
	char	*ptr = r;

	f.d = atof(number);
	printf("\tSingle-Precision :\n");
	printf("\t----------------\n\n");
	printf("- Binary Representation:\n");
	for (int i = sizeof(float) - 1; i >= 0; i--) {
		displayBinaryFormat(f.c[i], &ptr);
	}
	printf("\n\n");
	displaySinglePrecisionFormat(r);
}

void	doublePrecision(char *number) {
	dRep	d;
	char	r[SIZE_DOUBLE_FORMAT];
	char	*ptr = r;

	d.d = atof(number);
	printf("\tDouble-Precision :\n");
	printf("\t-----------------\n\n");
	printf("- Binary Representation:\n");
	for (int i = sizeof(double) - 1; i >= 0; i--) {
		displayBinaryFormat(d.c[i], &ptr);
	}
	printf("\n\n");
	displayDoublePrecisionFormat(r);
}

int	main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: ./repre number format\n");
		exit(EXIT_FAILURE);
	}
	if (!strcmp(argv[2], "single"))
		singlePrecision(argv[1]);
	else if (!strcmp(argv[2], "double"))
		doublePrecision(argv[1]);
	else
		fprintf(stderr, "Invalid format!\n");
	return 0;
}
