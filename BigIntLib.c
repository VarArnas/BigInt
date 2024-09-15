#include "BigIntLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



void makeEmpty(BigInt* a){
    for(int i=0; i< a->length; i++){
        a->digits[i] = 0;
    }
}

char* toString(BigInt a){
    int temp = 0;
    char* bigint = (char*)calloc((a.length), sizeof(char));
    if(bigint == NULL){
        return NULL;
    }
    if(a.sign == 1){
        a.length++;
        temp=1;
        bigint[0] = '-';
    }
    bigint = (char*)realloc(bigint, a.length*sizeof(char));
    if(bigint == NULL){
        return NULL;
    }
    for(int i=0+temp; i<a.length; i++){
        bigint[i] = a.digits[a.length-1-i]+'0';
    }
    bigint[a.length] = '\0';
    return bigint;
}

BigInt cloneBigInt(BigInt original) {
    BigInt clone;
    clone.sign = original.sign;
    clone.length = original.length;
    clone.digits = (int *) malloc(clone.length * sizeof(int));
    memcpy(clone.digits, original.digits, clone.length * sizeof(int));

    return clone;
}

void absolute(BigInt* a){
    if(a == NULL){
        return;
    }
    a->sign = 0;
}

BigInt originateBigInt(int length, int number) {
    BigInt bigint;
    bigint.sign = (number > 0)? 0 : 1;
    bigint.length = length;
    bigint.digits = (int*)calloc(length, sizeof(int));
    int posNumber = abs(number);
    for(int i=0; i<bigint.length; i++){
        bigint.digits[i] = posNumber%10;
        posNumber = posNumber/10;
    }
    return bigint;
}

BigInt fromString(char* str) {
    BigInt num;
    int temp = (str[0] == '-')? 1 : 0;
    num.sign = temp;
    int len = strlen(str)-temp;
    num.length = len;
    num.digits = (int*) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        if(str[len + temp - 1 - i] < 48 || str[len + temp - 1 - i] > 57){
            printf("in the given integer as a string there where symbols!!!\n");
            exit(-1);
        }
        num.digits[i] = str[len + temp -1 - i] - '0';
    }
    return num;
}

void appendDigit(BigInt* bigint, int digit) {
    bigint->length++;
    for(int i=bigint->length-1; i>=1; i--){
        bigint->digits[i] = bigint->digits[i-1];
    }
    bigint->digits[0] = digit;
    return;
}

bool isEmpty(BigInt a){

    for(int i=0; i<a.length; i++){
        if(a.digits[i] != 0){
            return 0;
        }
    }
    return 1;
}

void printBigInt(BigInt num) {
    if(num.length < 1){
        printf("BigInt was given too short of length!!!\n");
        return;
    }
    remove_leading_zeros(&num);
    if(num.sign == 1){
        printf("-");
    }
    for (int i = num.length-1; i >= 0; i--) {
        printf("%d", num.digits[i]);
        if(i%3 == 0 && i != 0 ){
            printf(",");
        }
    }
    printf("\n");
}

void free_bigint(BigInt *bigint) {
    free(bigint->digits);
    bigint->digits = NULL;
    bigint->sign = 0;
    bigint->length = 0;
}

void remove_leading_zeros(BigInt *bigint) {
    while (bigint->length > 1 && bigint->digits[bigint->length - 1] == 0) {
        bigint->length--;
    }
}

void swap(BigInt *a, BigInt *b) {
    BigInt temp = *a;
    *a = *b;
    *b = temp;
}

int compare(BigInt a, BigInt b) {
    remove_leading_zeros(&a);
    remove_leading_zeros(&b);
    if(a.sign != b.sign){
        return a.sign < b.sign;
    }
    if (a.length != b.length && a.sign == 0) {
        return a.length > b.length;
    }
    if(a.length != b.length){
        return a.length < b.length;
    }

    for (int i = a.length - 1; i >= 0; i--) {
        if (a.digits[i] != b.digits[i]) {
            if(a.sign == 0) return a.digits[i] > b.digits[i];
            return a.digits[i] < b.digits[i];
        }
    }

    return 1;
}

BigInt* subtract(BigInt a, BigInt b) {
    BigInt* result;
    int borrow = 0;
    int diff;

    if (a.sign == 1 && b.sign == 0) {
        b.sign = 1;
        result = add(a, b);
        b.sign = 0;
        return result;
    } else if (a.sign == 0 && b.sign == 1) {
        b.sign = 0;
        result = add(a, b);
        b.sign = 1;
        return result;
    } else if (a.sign == 1 && b.sign == 1) {
        b.sign = 0;
        result = add(a, b);
        b.sign = 1;
        result->sign = (compare(a, b))? 1 : 0;
        return result;
    }


    result = (BigInt*)malloc(sizeof(BigInt));

    if (!compare(a, b)) {
        swap(&a, &b);
        result->sign = 1;
    }

    result->length = a.length;
    result->digits = (int *) calloc(result->length, sizeof(int));

    for (int i = 0; i < b.length; i++) {
        diff = a.digits[i] - b.digits[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result->digits[i] = diff;
    }


    for (int i = b.length; i < a.length; i++) {
        diff = a.digits[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result->digits[i] = diff;
    }
    remove_leading_zeros(result);
    return result;
}

BigInt* add(BigInt a, BigInt b) {
    BigInt* result;
    result = (BigInt*)malloc(sizeof(BigInt));

    if (a.sign == b.sign) {
        result->sign = a.sign;
    } else {
        if (a.sign == 1) {
            a.sign = 0;
            result = subtract(b, a);
            a.sign = 1;
        } else {
            b.sign = 0;
            result = subtract(a, b);
            b.sign = 1;
        }

        return result;
    }

    int carry = 0;
    int sum = 0;
    int i;

    if (a.length > b.length) {
        result->length = a.length + 1;
    } else {
        result->length = b.length + 1;
    }

    result->digits = (int *) calloc(result->length, sizeof(int));
    for (i = 0; i < a.length && i < b.length; i++) {
        sum = a.digits[i] + b.digits[i] + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;
    }


    while (i < a.length) {
        sum = a.digits[i] + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;
        i++;

    }
    while (i < b.length) {
        sum = b.digits[i] + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;
        i++;
    }

    if (carry > 0) {
        result->digits[i] = carry;
    } else {
        result->length = i;
    }
    remove_leading_zeros(result);
    return result;
}

BigInt* multiply(BigInt a, BigInt b) {
    BigInt *result;
    result = (BigInt*) malloc(sizeof(BigInt));
    result->sign = (a.sign == b.sign)? 0 : 1;
    result->length = a.length + b.length;
    result->digits = (int *) calloc(result->length, sizeof(int));
    int carry, sum;
    for (int i = 0; i < a.length; i++) {
        carry = 0;
        for (int j = 0; j < b.length; j++) {
            sum = result->digits[i+j] + a.digits[i] * b.digits[j] + carry;
            result->digits[i+j] = sum % 10;
            carry = sum / 10;
        }
        result->digits[i+b.length] = carry;
    }
    if(a.digits[0] == 0 || b.digits[0] == 0){
        result->sign = 0;
    }
    remove_leading_zeros(result);
    return result;
}


BigInt *divide(BigInt a, BigInt b) {
    if (b.length == 1 && b.digits[0] == 0) {
        printf("Error: dalyba is nulio!!!\n");
        exit(-1);
    }

    BigInt *result = (BigInt*)malloc(sizeof(BigInt));
    result->length = 1;
    result->digits =(int*)calloc(a.length, sizeof(int));
    remove_leading_zeros(result);

    if (a.length == 1 && a.digits[0] == 0) {
        result->digits = (int *) calloc(1, sizeof(int));
        result->length = 1;
        result->digits[0] = 0;
        result->sign = 0;
        return result;
    }

    if (!compare(a, b)) {
        result->digits = (int *) calloc(1, sizeof(int));
        result->length = 1;
        result->digits[0] = 0;
        result->sign = 0;
        return result;
    }
    BigInt temp = originateBigInt(10000, 0);
    temp.length = 1;
    bool check_loop = 0;
    temp.sign = 0;
    temp.digits[0] = a.digits[a.length-1];
    int quotient = 0;
    int save_sign = b.sign;
    b.sign = 0;
    while (compare(temp, b)) {
        temp = *subtract(temp, b);
        quotient++;
        check_loop = 1;
    }
    result->digits[a.length-1] = quotient;
    for (int i = a.length - 2; i >= 0; i--) {
        if(check_loop && temp.digits[0] == 0){
            temp.length = 0;
            check_loop = 0;
        } else if(check_loop){
            check_loop = 0;
        }
        appendDigit(&temp, a.digits[i]);
        quotient = 0;
        while (compare(temp, b)) {
            b.sign = 0;
            temp = *subtract(temp, b);
            quotient++;
            check_loop = 1;
        }
        result->length++;
        result->digits[i] = quotient;
    }
    b.sign = save_sign;
    result->sign = a.sign ^ b.sign;
    remove_leading_zeros(result);
    free_bigint(&temp);
    return result;
}


BigInt* mod(BigInt a, BigInt b){
    BigInt* result = (BigInt*)malloc(sizeof(BigInt));

    result->length = b.length;
    result->digits = (int*)calloc(b.length, sizeof(int));
    int save_sign = a.sign;

    BigInt multiplier = originateBigInt(a.length, 0);
    BigInt sub = originateBigInt(b.length, 0);
    multiplier = *divide(a, b);
    sub = *multiply(multiplier, b);
    sub.sign = 0;
    a.sign = 0;
    result = subtract(a, sub);
    result->sign = save_sign;
    if(a.digits[0] == 0 || b.digits[0] == 0){
        result->sign = 0;
    }
    free_bigint(&multiplier);
    free_bigint(&sub);
    return result;

}
