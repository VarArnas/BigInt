#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BigIntLib.h"

#define intToBigInt 4758245
#define lengthOfBigInt 10

#define stringToBigIntNum "-000042745272730000"

int main() {

    BigInt a = originateBigInt(lengthOfBigInt, intToBigInt);
    BigInt b = fromString(stringToBigIntNum);
    char* c = ToString(a);
    BigInt* div = divide(a, b);
    BigInt* sum = add(a, b);
    BigInt* sub = subtract(a, b);
    BigInt* mul = multiply(a, b);
    BigInt* moderator = mod(a, b);
    printf("skaicius a = ");
    printBigInt(&a);
    printf("skaicius b = ");
    printBigInt(&b);
    printf("sum  = ");
    printBigInt(sum);
    printf("sub  = ");
    printBigInt(sub);
    printf("mul  = ");
    printBigInt(mul);
    printf("div  = ");
    printBigInt(div);
    printf("mod  = ");
    printBigInt(moderator);
    free_bigint(&a);
    free_bigint(&b);
    free_bigint(sum);
    free_bigint(sub);
    free_bigint(div);
    free_bigint(moderator);
    free(c);
    return 0;
}
