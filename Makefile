main: main.o imagehelpers.o shapes.o
	g++ -o main main.o imagehelpers.o

main.o: main.cpp imagehelpers.h

shapes.o:shapes.cpp

imagehelpers.o: imagehelpers.cpp imagehelpers.h

clean:
	rm -f main.o imagehelpers.o shapes.o main taska.pgm taskb.pgm taskc.pgm taskd.pgm taske.pgm taskf.pgm z.pgm
