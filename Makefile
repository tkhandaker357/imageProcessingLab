main: main.o invert.o imageio.o
	g++ -Wall -o main main.o invert.o imageio.o

main.o: main.cpp invert.hpp imageio.h

invert.o: invert.cpp invert.hpp imageio.h 

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h


clean:
	rm -f sample.o imageio.o main.o invert.o
