apc.exe : main.o apc.o add.o sub.o mul.o div.o print.o
	gcc -o apc.exe main.o apc.o add.o sub.o mul.o div.o print.o
main.o : main.c 
	gcc -c main.c 
apc.o : apc.c 
	gcc -c apc.c 
add.o : add.c 
	gcc -c add.c 
sub.o : sub.c 
	gcc -c sub.c 
mul.o : mul.c 
	gcc -c mul.c 
div.o : div.c 
	gcc -c div.c 
print.o : print.c
	gcc -c print.c	
clean :
	rm -f *.o apc.exe  