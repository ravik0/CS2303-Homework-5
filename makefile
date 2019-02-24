all:  sorttest

sorttest: sorttest.o sort.o timesort.o
	gcc -g sorttest.o sort.o timesort.o -o sorttest

sorttest.o: sorttest.c sort.h
	gcc -g -c --std=gnu89 sorttest.c

sort.o: sort.c sort.h
	gcc -g -c --std=gnu89 sort.c

timesort.o: timesort.c sort.h
	gcc -g -c --std=gnu89 timesort.c

clean:
	rm -f  *.o sorttest
	rm -r -f html latex

docs:
	doxygen
