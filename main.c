#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BigIntLib.h"

#define intToBigInt 0
#define lengthOfBigInt 6

#define stringToBigIntNum "465"


int main() {

    BigInt a = originateBigInt(lengthOfBigInt, intToBigInt);
    BigInt b = fromString(stringToBigIntNum);
    char* c = toString(a);
    BigInt* div = divide(a, b);
    BigInt* sum = add(a, b);
    BigInt* sub = subtract(a, b);
    BigInt* mul = multiply(a, b);
    BigInt* moderator = mod(a, b);
    printf("print first BigInt as a string: %s \n", c);
    printf("comparing two big ints: %d\n", compare(a, b));
    printf("number a = ");
    printBigInt(a);
    printf("number b = ");
    printBigInt(b);
    printf("sum  = ");
    printBigInt(*sum);
    printf("sub  = ");
    printBigInt(*sub);
    printf("mul  = ");
    printBigInt(*mul);
    printf("div  = ");
    printBigInt(*div);
    printf("mod  = ");
    printBigInt(*moderator);
    free_bigint(&a);
    free_bigint(&b);
    free_bigint(sum);
    free_bigint(sub);
    free_bigint(div);
    free_bigint(moderator);
    free(c);
    return 0;
}
