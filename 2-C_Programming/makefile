market : market.c manager.o product.o
	gcc -o market market.c product.o manager.o
manager.o : manager.c manager.h
	gcc -c manager.c
product.o : product.c product.h
	gcc -c product.c
clean : 
	rm *.o market
