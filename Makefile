all: add-nbo

add-nbo.o: add-nbo.cpp
	g++ -c -o add-nbo.o add-nbo.cpp

add-nbo: add-nbo.o
	g++ -o add-nbo add-nbo.o

clean:
	rm -f *.o add-nbo
