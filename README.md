# BigInt

A program for implementing the BigInt (i.e. being able to do arithmetic with larger numbers than long double) in C utilizing dynamic memory allocation.  

FUNCTIONS:

add - adds two BigInt data types and returns a pointer to the newly created BigInt
subtract - subtracts two BigInt data types and returns a pointer to the newly created BigInt
appendDigit - helper function, to append one digit to the start of the BigInt struct
MakeEmpty - helper function, to turn all BigInt digits to 0
ToString - returns a string holding BigInt digits, by reversing the structs digits order
cloneBigInt - deep clones a BigInt struct and returns a BigInt
absolute - makes the BigInt positive
originateBigInt - creates a BigInt struct, from a given integer and the given length
fromString - creates a BigInt struct, from a string
printBigInt - prints the BigInt struct in reverse order
free_bigint - releases the memory allocated for the BigInt struct
remove_leading_zeros - removes any leading zeros inside a BigInt struct
swap - swaps pointers of two variables of BigInt with one another
compare - compares two BigInts, and returns 1 if the first BigInt given, is more or equal to the second BigInt, else returns 0
multiply - multiplies two BigInt structs and returns a pointer to the new BigInt struct
divide - divides two BigInt structs (the first BigInt out of the second) and returns a pointer to the new BigInt struct
mod - finds the mod of two BigInt structs (when dividing the first BigInt out of the second), and returns a pointer to the new BigInt struct


HOW TO RUN:

* Navigate to the directory of the project through the terminal
* Run command "make"
* Run command "BigInt.exe"

  
