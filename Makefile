all: c a m u
a: c
	clang -fsanitize=address *.c && ./a.out
m: c
	clang -fsanitize=memory *.c && ./a.out
u: c
	clang -fsanitize=undefined *.c && ./a.out
mike:
	cat *.c > mike.c
	cat utils >> mike.c
ccomp: c mike
	ccomp mike.c && ./a.out
interp: c mike
	ccomp -interp -quiet mike.c
c:
	rm -rf mike.c *.o *.out
