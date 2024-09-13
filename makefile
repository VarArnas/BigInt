BigInt: main.o BigIntLib.o
	gcc -std=c99 -o BigInt main.o BigIntLib.o

main.o: main.c
	gcc -c -std=c99 main.c

BigIntLib.o: BigIntLib.c BigIntLib.h
	gcc -c -std=c99 BigIntLib.c