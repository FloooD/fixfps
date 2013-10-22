all:
	gcc -m32 -O3 -c -fomit-frame-pointer -fpic -o temp.o fixfps.c
	gcc -m32 -O3 -fomit-frame-pointer -shared -o fixfps.so temp.o -lrt
	rm temp.o
