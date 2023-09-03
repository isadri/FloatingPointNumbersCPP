# Floating-Point Numbers

Everything is stored in computers in the form of bits, which means that everything is stored as binary numbers. But some kinds of numbers are definitely easier to express in terms of bits than others.

To represent what mathematicians call the positive *************whole numbers************* and what programmers call the positive *****************integers*****************, you can take the given positive integer and recursively dividing it by 2. Then the remainders are noted down till you get 0 as the final quotient. After this step, the remainders are written in reverse order to get the binary value of the given positive integer. For example, let’s convert the integer 234 to binary:

| Dividend | Divisor | Quotient | Remainder |
| --- | --- | --- | --- |
| 234 | 2 | 117 | 0 |
| 117 | 2 | 58 | 1 |
| 58 | 2 | 29 | 0 |
| 29 | 2 | 14 | 1 |
| 14 | 2 | 7 | 0 |
| 7 | 2 | 3 | 1 |
| 3 | 2 | 1 | 1 |
| 1 | 2 | 0 | 1 |

Thus, the integer 234 is 11101010 in binary.

Some computers use a sign in the binary representation of a number to indicate that this number is negative or positive, this sign is the most-significant bit (i.e., the left most bit), and is called the ********sign bit********. If the sign bit is 0, then the number is positve, otherwise, is negative.

For the negative integers, you can use a method know as *******the two’s complement******* to represent a given negative integer. This method involves the following steps:

1. Take the absolute value of the negative integer and convert it to its binary form.
2. Convert each 0 to 1 and each 1 to 0 (this method is called *********************the one’s complement*********************).
3. Add 1 to the binary number produced by the one’s complement.

For example, to represent -120 in binary:

1. The absolute value of -120 is 120, and 120 in binary is 01111000.
2. Using the one’s complement, 01111000 will be 10000111.
3. Adding one to 10000111, we get 10001000.

So -120 is 10001000 in binary (notice the sign bit is 1, which means that this number is negative).

Mathematicians define another type of numbers called the *rational numbers* as those numbers that can be represented as a ratio of two whole numbers. This ratio is also referred to as a ********fraction********. For example, 3/4 is a rational number because it’s the ratio of 3 and 4. We can also write this number in decimal fraction, or just decimal, form: 0.75. When we write it as a decimal, it really indicates a fraction, in this case 75/100.

In decimal number system, digits to the left of the decimal point are multiples of integral powers to ten. Similarly, digits to the right of the decimal point are multiples of negative powers of ten.

<img width="665" alt="Screen_Shot_2023-08-21_at_2 24 59_PM" src="https://github.com/es-liby/FloatingPointNumbersCPP/assets/116354167/00ce17d7-fe14-48f2-8e03-6d0f877513c2">


For example, 42,705.684 is equal to

$4 * 10,000$  +

$2 * 1000$ +

$7 * 100$ +

$0 * 10$ +

$5 * 1$ +

$6 / 10$ +

$8 / 100$ +

$4 / 1000$

We can write this sequence without any division:

$4 * 10,000$ +

$2 * 1000$ +

$7 * 100$ +

$0 * 10$ +

$5 * 1$ +

$6 * 0.1$ +

$8 * 0.01$ +

$4 * 0.001$

We can also write this sequence using powers of ten

4 * 10^4 +

2 * 10^3 +

7 * 10^2 +

0 * 10^1 +

5 * 10^0 +

6 * 10^(-1) +

8 * 10^(-2) +

4 * 10^(-3)

Some rational numbers aren’t so easily represented as decimals, the moset obvious being 1/3. If you divide 3 into 1, you’ll fine that 1/3 is equal to

$$
0.33333333333333333333333333333333333333333333333333333333333333333333333333...
$$

Even though writing 1/3 as a decimal fraction is a bit awkward, it’s still a rational number because it’s the ratio of two integers.

*Irrational numbers* are monsters such as the square root of 2. This number can’t be expressed as the ratio of two inetegers, which means that the decimal fraction continues indefinitely without any repitition or pattern:

$$
√2 ≈ 1.41421356237309504880168872420969807856967187537694…
$$

All the numbers we’ve been talking about so far - rational numbers and irrational numbers - are called ************real numbers************.

We’re accustomed to thinking of numbers as **********continuous**********. If you give me two rational numbers, I can give you a number between those two numbers. But computers can’t deal with continuums. Bits are either 0 or 1, with nothing in between. So by their nature, computers must deal with ********discrete******** value. The number of discrete values you can represent is directly related to the number of bits you have available. For example, if you choose to store positive integers using 32 bits, the values that you can store are the whole numbers from 0 through 4,294,967,295. If you need to store the value 4.5, you must rethink you approach and do something different. What you can do is make the fractional number looks like an integer, for example, 4.5 can be written as 45 * 10^(-1). Hence you can reperesent 4.5 as 45, but the problem is when you need to perform some operation on this number, such as add it to another number, so you need to remember where the decimal point is located. You can determine the position of the decimal point using the number you use it as the power (let’s call it **n**) of 10 to make the fractional number looks like an integer number multiple 10^(n). n represents how many time the decimal point will be shifted in order to get the actual, if n is positive, it indicates that the decimal point should be shifted right, if n is negative, the decimal point should be shifted left. So to get the actual value of 45 * 10^(-1), we shift the decimal point according to n, here we have n = -1, so we shift the decimal point one position to the left and we get 4.5, and that is the fractional number. Another example, we have 234.185, and we want it to be written as 234185 * 10^n, it is obvious that we must shift the decimal point three position to the left so n will be -3. Thus, to represent any fractional number as integer, we just multiply that fractional number by ten to the power of how many times we want to shift the decimal point; 4.5 * 10^1 (shift one position to the right), 234.185 10^3 (shift three position to the right), and to get back the fractional number we multiply by ten to the power of the negative number of times the decimal point has shifted; 45 * 10^(-1) = 4.5 (shift one position to the right), 234185 * 10(-3) = 234.185 (shift three positions to the left).

So, we manage to represent a fractional as an integer, even though we need to remember how many time we shift the decimal point in order to perform operations, such as arithmetic operation. This representation widely used, and is known as the ************************************************fixed-point************************************************ representation.

## Fixed-Point

A fixed-point is a way of representing fractional numbers by storing a fixed number of digits of their fractional part.

A fixed-point representation of a fractional number is essentially an integer that is to be implicitly multiplied by a fixed scaling factor. The fraction is often expressed in the same number base as the integer part, but using negative powers of the base b. Thus, if *n* fraction digits are stored, the value will always be an integer multiple of b ^ (-n). For example, the value 1.23 can be store in a variable as the integer 1230 with implicit scaling factor of 10^(-3) (meaning that the last 3 decimal digits are implicitly assumed to be a decimal fraction, i.e., shifting the decimal point 3 position to the left), and the value 1,230,000 can be represented as 1230 with an implicit scaling factor of 10^3 (shift the decimal point 3 position to the right, with 3 implicit zero digits at right). As you recall this representation allows standard integer arithmetic units to perform rational number calculations.

The same method can be done using base 2 as a scaling factor (**************binary scaling**************). Base 2 is very useful in computer program, for example, if we want to multiply an integer by 2 ^ n, it’s sufficient to shift the integer ***n*** position to the left or to the right (according the sign of *n*), which is faster.

In order to convert a floating-point value to the corresponding fixed-point value us the following steps, consider a floating-point variable **a**:

1. Calculate *b* = *a* * 2 ^ *F*, where *F* is the fractional length of the variable.
2. Round the value of *b* to the nearest integer value.

For example, assume that we want to convert 16.125 to fixed-point representation and we want 2 as fractional bits, thus, *b* = 16.125 * 2 ^ 2 = 64.5, rounding **b** gives: round(*b*) = 64. So 64 is the fixed-point representation of the number 16.125.

### Addition and Subtraction

To add or subtract two values with the same implicit scaling factor, it is sufficient to add or subtract the underlying integers, the result will have their common implicit scaling factor, can thus be stored in the same program variables as the operands. These operations yield the exact result, as long as no overflow occurs. If the values have different scaling factors, then they must be converted to common scaling factor before the operation, for example, let’s add 4.5 to 2.25, first we need to convert them to fixed-point representation, we choose that we want 8 fractional bits for the first operand, thus 4.5 is equal round(4.5 * 2 ^ 8) = 1152, and 3 fractional bits for the second operand, round(2.25 * 2 ^ 3) = 18. But in order to perform addition or subtraction, we need to find a common factor, notice that the first operand has a factor equal to 256 (2 ^ 8) and the seconde one has a factor equal to 8 (2 ^ 3), if we multiply 8 by 32 we’ll get 256, so 256 will be our common factor, hence 2.25 will be round(2.25 * 2 ^ (3) * 2 ^ (5)) = 576. Thus, 1152 + 576 = 1728, to get the integer value, we divide the result by 256, 1728 / 256 (or 1728 * 2 ^ (-8), we get 6.75, which is exactly 4.5 + 2.25 = 6.75.

### Multiplication

To multiply two fixed-point numbers, it suffices to multiply the two underlying integers, and assume that the scaling factor of the result is the product of their scaling factors. The result will be exact, with no rounding, provided that it does not overflow the receiving variable.

For example, let’s take 3.125 and 6 as operands, and 2 fractional bits for the first one and 3 for the second one, convert them into fixed-point format: round(3.125 * 2 ^ 2) = 12.5, round(6 * 2 ^ 3) = 48, then 12.5 * 48 = 600, thus to get the actual value we divide 600 by ((2^2) * (2 ^ 3)) = 32: 600 / 32 = 18.75. To check, multiply the actual operands, 3.125 * 6 = 18.75.

### Division

To divide two fixed-point numbers, we need to divide the underlying integers, and the scaling factor of the result is the quotions of their scaling factors.

For example, dividing 4.8 by 2, 4 fractional bits for 4.8 and 3 fractional bits for 2. Hence round(4.8 * 2 ^ 4) = 76.8, round(2 * 2 ^ 3) = 16, the scaling factor is : 2 ^ 4 / 2 ^ 3 = 2, thus 76.8 / 16 = 4.8, divide by 2 we get 2.4, which is 4.8 / 2 = 2.4. 

Fixed-point format works well only if you know that numbers aren’t going to get too large for the memory location that you’ve mapped out and that you won’t need more decimal places. Where fixed-point format utterly fails is in situations in which numbers can get very large or very small. Suppose you need to reserve an area of memory where you can store certain distances in units of feet. The problem is that these distances can range all over the place. The distance from the earth to the sun is 490,000,000,000 feet, and the radius of the hydrogen atom is 0.00000000026 feet. You’d need more bytes of fixed-point storage to accomodate values that can get as large as small as these.

## Floating-point Representation

We porbably use another approach that scientists and engineers enjoy specifying numbers using a system called ***********scientific notation***********. Scientific notation is particularly useful for representing very large and very small numbers because it incorporates a power of ten that allows us to avoid writing out long strings of zeors. In scientific notation, the number 490,000,000,000 is written 4.9 * 10 ^ 11 and the number 0.00000000026 is written 2.6 * 10 ^ (-10). In these two examples, the numbers 4.9 and 2.6 are called the *************fraction part*************, or the ***characteristic***, or sometimes the ********mantissa********. But to be more in tune with the terminology use with computers, we’re going to call this part of scientific notation the ***********significand***********.

The exponent part is the power to which 10 is raised. In the first example, the exponent is 11, and the in the second example, the exponent is -10. As you recall, the exponent tells you how many places the decimal point has been moved in the significand.

By convention, the significand is always greater than or equal to 1 and less than 10, that’s sometimes called the **********normalized********** form of scientific notation.

In computers, the alternative to fixed-point notation is called **************floating-point************** notation, and the floating-point format is ideal for storing small and large numbers because it’s based on scientific notation. But the floationg-point format as used in computers employs *******binary******* numbers written in scientific notation. The first thing we have to figure out is what fractional number look like in binary.

In decimal notation, digits to the right of the decimal point represent negative powers of ten. In binary notaion, digits to the right of the ****binary point**** represent negative powers of two. For example, this binary number

$$
101.1101
$$

can be converted to decimal using this formula:

1 * 4 +

0 * 2 +

1 * 1 +

1 / 2 +

1 / 4 +

0 / 8 +

1 / 16

The division signs can be replaced with negative powers of two:

1 * 2 ^ 2 +

0 * 2 ^ 1 +

1 * 2 ^ 0 +

1 * 2 ^ (-1) +

1 * 2 ^ (-2) +

0 * 2 ^ (-3) +

1 * 2 ^ (-4)

Or the negative powers of two can be calculated by starting at 1 and repeatedly dividing by 2:

1 * 4 +

0 * 2 +

1 * 1 +

1 * 0.5 +

1 * 0.25 +

0 * 0.125 +

1 * 0.0625

By this calculation, the decimal equivalent of 101.1101 is 5.8125.

In decimal scientific notation, the normalized significand should be greater than or equal to 1 but less than 10. Similarly, the normalized significand of numbers in binary scientific notation is always greater than on equal to 1 but less than binary 10, which is 2 in decimal. So in binary scientific notation, the number 101.1101 is expressed as 1.011101 * 2 ^ 2.

One interesting implication of this rule is that a normalized binary floating-point number always has a 1 and nothing else at the left of the binary point.

Most contemporary computers and computer programs that deal with floating-point numbers use a standard established by IEEE (the Institute of Electrical and Electronics Engineers) in 1985, a standard also recognized by ANSI (the American National Standards Insititute). ANSI/IEEE Std 754 is called the ***IEEE Standard for Binary Floating-Point Arithmetic***.

The IEEE floating-point standard defines two basic formats: single precision, which requires 4 bytes, and double precisino, which requires 8 bytes.

Let’s look at the single-precision format first. It has three parts: a 1-bit sign (0 for positive and 1 for negative), an 8-bit exponent, and a 23-bit significand fraction arranged like this, with the least-significand bits on the right:

| s = 1-Bit Sign | e = 8-Bits Exponent | f = 23-Bit Significand Fraction |
| --- | --- | --- |

That’s a total of 32 bits, or 4 bytes. Because the significand of a normalized binary floating-point number always has a 1 to the left of the binary point, that bit is not included in the storage of floating-point numbers in the IEEE format. The 23-bit ********fraction******** part of the significand is the only part stored. So even though only 23 bits are used to store the significand, the *********precision********* is said to be 24 bits.

The 8-bit exponent part can range from 0 through 255. This is called a *******biased******* exponent, which means that you must subtract a number - called the ****bias**** - from the exponent in order to determine the signed exponent that actually applies. For single-precision floating-point numbers, this bias is 127.

The exponent is biased - the value stored is offset from the actual value by the *************exponent bias*************, also called a ***************biased exponent***************. Biasing is done because exponents have to be signed values in order to be able to represent both tiny and huge values, but two’s complement, the usual representation for signed values, would make comparison harder.
To solve this problem, the exponent is stored as an unsigned value which is suitable for comparison, and when being interpreted it is converted into an exponent within a signed range by subtracting the bias.
By arranging the fields such that the sign bit takes the most significant bit position, the biased exponent takes the middle position, then the significand will be the least significant bits and the resulting value will be ordered properly. This is the case whether or not it is interpreted as a floating-point or integer value. The purpose of this is to enable high speed comparisons between floating-point numbers using fixed-point hardware.
To calculate the bias for an arbitrary sized floating-point number apply the formula 2 ^ (k - 1) - 1, where k is the number of bits in the exponent.
When interpreting the floating-point number, the bias is subtracted to retrieve the actual exponent.

If the exponent ranges from 1 through 254, the number represented by particular values of *s* (the sign bit), *e* (the exponent), and *f* (the significand fraction) is ************(-1) ^ s * 1.f * 2 ^ (e - 127)************.

That negative 1 to the *s* power is a mathematician’s annoyingly clever way of saying, “if *s* is 0, the number is positive, and if ***s*** is 1, the number is negative”.

The next part of the expression is 1.*f*, which means a 1 followed by a binary point, followed by the 23 bits of the siginificand notation. This is multiplied by 2 to a power. The exponent is the 8-bit biased exponent stored in memory minus 127.

There are special cases:

- If *e* = 0 and *f* = 0, the number is 0. Generally, all 32 bits are set to 0 to signify 0. But the sign bit can be 1, in which case the number is interpreted as a negative 0. A negative 0 can indicate a very small number that can’t be represented with the available digits and exponents in single-precision format but which is still less than 0.
- If *e* = 0 and *****f***** ≠ 0, the number is valid, but it’s not normalized. The number equals (-1) ^ s * 0.f * 2 ^ (-127). Notice that the significand has a 0 to the left of the binary point.
- If ****e**** = 255 and *f* = 0, the number is positive or negative infinity, depending on the sign *s*.
- If **e** = 255 and *f* ≠ 0, the value is considered to be not a number, which is abreviated NaN. A NaN could indicate an unknown number or the result of an invalid operation.


<img width="1048" alt="Screen Shot 2023-09-02 at 9 50 51 AM" src="https://github.com/es-liby/FloatingPointNumbersCPP/assets/116354167/2a6ed03b-d8e9-492c-b1f4-e3f22c4d007f">


The smallest normalized positive or negative binary that can be represented in single-precision floating-point format is:

1.00000000000000000000000 * 2 ^ (-126)

The largest normalized positive or negative number is that can be represented in single-precision floating-point format is this:

1.11111111111111111111111 * 2 ^ 127

10 binary digits are approximately the same as 3 decimal digits. Which means that 10 bits set to 1 is approximately equal to 3 decimal set to 9, or 999, or 2 ^ 10 ≈ 10 ^ 3. This relationship implies that the 24-bit binary number stored in single-precision floating-point format is roughly the equivalent of 7 decimal digits. For this reason, it’s said that the single-precision floating-point offers a ********precision******** of 24 bits, or about 7 decimal digits.

If you try to represent both 16,777,216 and 16,777,217 as single-precision floating-point numbers, they’ll end up being identical. Moreover, any number between those two (such as 16,777,216.5) is also considered to be identical.

If floating-point notation is what you want but single-precision doesn’t quite hack it, you’ll probably want to use ****************double-precision**************** floating-point format. These numbers require 8 bytes of storage, arranged like this:

| s = 1-Bit Sign | e = 11-Bits Exponent | f = 51-Bit Significand Fraction |
| --- | --- | --- |

The exponent bias is 1023, so the number stored in such a format is ******(-1) ^ s * 1.f * 2 ^ (e - 1023)******.

Similar rules as those we encountered with single-precision format apply for 0, infinity, and NaN.

The smallest positive or negative double-precision floating-point number is

1.0000000000000000000000000000000000000000000000000000 * 2 ^ (-1022)

The largest is

1.1111111111111111111111111111111111111111111111111111 * 2 ^ 1023

The 53 bits of the significand (including the 1 bit that’s not included) is a resolution approximately equivalent to 16 decimal digits. This is much better than single-precision floating-point format, but it still means that eventually some number will equal some other number.
