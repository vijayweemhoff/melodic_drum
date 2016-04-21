CC = g++
CFLAGS = -I/usr/local/include -Wall
LDFLAGS= -L/usr/local/lib -lportaudio -lpthread -llo


OBJ= melodic_main.o

all: melodic_main

melodic_main: $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
