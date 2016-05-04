all: my_printf


my_printf: my_printf.o my_printf.c
	gcc -m32 -o my_printf.o my_printf.c


clean:
	rm *o

