#ifndef BIGINTLIB_H_INCLUDED
#define BIGINTLIB_H_INCLUDED



typedef struct {
    int* digits;
    int length;
    int sign;
} BigInt;

BigInt *add(BigInt a, BigInt b);
BigInt* subtract(BigInt a, BigInt b);
void appendDigit(BigInt* bigint, int digit);
void MakeEmpty(BigInt* a);
char* ToString(BigInt a);
BigInt cloneBigInt(BigInt original);
void absolute(BigInt* a);
BigInt originateBigInt(int length, int number);
BigInt fromString(char* str);
void printBigInt(BigInt* num);
void free_bigint(BigInt *bigint);
void remove_leading_zeros(BigInt *bigint);
void swap(BigInt *a, BigInt *b);
int compare(BigInt a, BigInt b);
BigInt* multiply(BigInt a, BigInt b);
BigInt *divide(BigInt dividend, BigInt divisor);
BigInt* mod(BigInt dividend, BigInt divisor);


#endif
