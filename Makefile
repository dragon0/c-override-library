
all: leak libsample.so

libsample.so: alloc.o
	gcc -shared -Wl,-soname,libsample.so -o libsample.so alloc.o -lc -ldl

alloc.o: alloc.c
	gcc -fPIC  -c alloc.c
# fPIC flag instructs the compiler to produce position independent code, so that it shall be used for creating dynamic libraries.

clean:
	rm -v leak *.o *.so


run:
	LD_PRELOAD=./libsample.so ./leak

