TARGET = Mystring

all : ${TARGET}

Mystring : main.o Mystring.o
	cc -o Mystring main.o Mystring.o

main.o : main.c Mystring.h
	cc -c main.c

Mystring.o : Mystring.c
	cc -c Mystring.c

clean :
	rm ${TARGET}