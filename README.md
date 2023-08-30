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

For the negative integers, you can use a method know as *******the two’s complement******* to represent a given negative intger. This method involves the following steps:

1. Take the absolute value of the negative integer and convert it to its binary form.
2. Convert each 0 to 1 and each 1 to 0 (this method is called *********************the one’s complement*********************).
3. Add 1 to the binary number produced by the one’s complement.

For example, to represent -120 in binary:

1. The absolute value of -120 is 120, and 120 in binary is 01111000.
2. Using the one’s complement, 01111000 will be 10000111.
3. Adding one to 10000111, we get 10001000.

So -120 is 10001000 in binary (notice the sign bit is 1, which means that this number is negative).

    Mathematicians define another type of numbers called the *rational numbers* as those numbers that can be represented as a ratio of two whole numbers. This ratio is also referred to as a ********fraction********. For example, 3/4 is a rational number because it’s the ratio of 3 and 4. We can also write this number in decimal fraction, or just decimal, form: 0.75. When we write it as a decimal, it really indicates a fraction, in this case 75/100.

In decimal number system, digits to the left of the decimal point are multiples of integral powers to ten. Similarly, digits to the right of the decimal point are multiples of negarive powers of ten.

<!--![Screen Shot 2023-08-21 at 2.24.59 PM.png](Floating-Point%20Numbers%200c1d77ccc6694ca9882febcabb9b7609/Screen_Shot_2023-08-21_at_2.24.59_PM.png)-->

<img src=”https://github.com/es-liby/FloatingPointNumbersCPP/assets/116354167/86c16260-fff4-4d11-b929-76a1356cb118" alt=”my banner”>

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

    We’re accustomed to thinking of numbers as **********continuous**********. If you give me two rational numbers, I can give you a number between those two numbers. But computers can’t deal with continuums. Bits are either 0 or 1, with nothing in between. So by their nature, computers must deal with ********discrete******** value. The number of discrete values you can represent is directly related to the number of bits you have available. For example, if you choose to store positive integers using 32 bits, the values that you can store are the whole numbers from 0 through 4,294,967,295. If you need to store the value 4.5, you must rethink you approach and do something different. Whay you can do is make the fractional number looks like an integer, for example, 4.5 can be written as 45 * 10^(-1). Hence you can reperesent 4.5 as 45, but the problem is when you need to perform some operation on this number, such as add it to another number, so you need to remember where the decimal point is located. You can determine the position of the decimal point using the you use it as the power (let’s call it **n**) of 10 to make the fractional number looks like an integer number multiple 10^(n). n represents how many time the decimal point is shifted, if n is positive, it indicates that the decimal point is shifted right, if n is negative, the decimal point is shifted left. Thus, if we want to retreive the actual value, we need to shift the decimal point in the reverse order, if n ≥ 0, we shift to the left, if n < 0 we shift to the right. So to get the actual value of 45 * 10^(-1), we shift the decimal point according to n, here we have n = -1, so we shift the decimal point to the left and we get 4.5, and that is the fractional number. Another example, we have 234.185, and we want it to be written as 234185 * 10 (n), it is obvious that we must shift the decimal point three position to the right so n will be -3. Thus, to represent any fractional number as integer, we just multiply that fractional number by ten to the power of how many times we want to shift the decimal point; 4.5 * 10^1 (shift one position to the right), 234.185 10^3 (shift three position to the right), and to get back the fractional number we multiply by ten to the power of the negative number of times the decimal point has shifted; 45 * 10^(-1) = 4.5, 234185 * 10(-3) = 234.185.

    So, we manage to represent a fractional as an integer, even though we need to remember how many time we shift the decimal point in order to perform operations, such as arithmetic operation. This representation widely used, and is known as the ************************************************fixed-point************************************************ representation.

## Fixed-Point

A fixed-point is a way of representing fractional numbers by storing a fixed number of digits of their fractional part.

A fixed-point representation of a fractional number is essentially an integer that is to be implicitly multiplied by a fixed scaling factor. The fraction is often expressed in the same number base as the integer part, but using negative powers of the base b. Thus, if *n* fraction digits are stored, the value will always be an integer multiple of b ^ (-n). For example, the value 1.23 can be store in a variable as the integer 1230 with implicit scaling factor of 10^(-3) (meaning that the last 3 decimal digits are implicitly assumed to be a decimal fraction, i.e., shifting the decimal point 3 position to the left), and the value 1,230,000 can be represented as 1230 with an implicit scaling factor of 10^3 (shift the decimal point 3 position to the right, with 3 implicit zero digits at right). As you recall this representation allows standard integer arithmetic units to perform rational number calculations.