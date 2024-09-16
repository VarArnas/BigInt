# Implementation of a BigInt Data Structure

A program for implementing the BigInt (i.e. being able to do arithmetic with larger numbers than long double) in C utilizing dynamic memory allocation. Can be used as a BigInt data structure in other projects. A makefile has been written to launch the program easily without the need of an IDE

<br>

FUNCTIONS
---

- **add** - adds two BigInt data structures and returns a pointer to the newly created BigInt.

- **subtract** - subtracts two BigInt data structures and returns a pointer to the newly created BigInt.

- **appendDigit** - helper function, to append one digit to the start of the BigInt struct.

- **makeEmpty** - helper function, to turn all BigInt digits to 0.

- **toString** - returns a string holding BigInt digits, by reversing the structs digits order.

- **cloneBigInt** - deep clones a BigInt structure and returns a BigInt.

- **absolute** - makes the BigInt positive.

- **originateBigInt** - creates a BigInt structure, from a given integer and the given length.

- **fromString** - creates a BigInt structure, from a string.

- **printBigInt** - prints the BigInt structure in reverse order.

- **free_bigint** - releases the memory allocated for the BigInt struct.

- **remove_leading_zeros** - removes any leading zeros inside a BigInt struct.

- **swap** - swaps pointers of two variables of BigInt with one another.

- **compare** - compares two BigInts, and returns 1 if the first BigInt given, is more or equal to the second BigInt, else returns 0.

- **multiply** - multiplies two BigInt structures and returns a pointer to the new BigInt struct.

- **divide** - divides two BigInt structures (the first BigInt out of the second) and returns a pointer to the new BigInt struct.

- **mod** - finds the mod of two BigInt structures (when dividing the first BigInt out of the second), and returns a pointer to the new BigInt struct.

<br>

HOW TO RUN:
---

* Navigate to the directory of the project through the terminal
* Run command `make`
* Run command `BigInt.exe`

  
