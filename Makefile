CC=g++
CPPFLAGS= -Wall -std=c++11 -O2 -I./shared 
LINKFLAGS = -lpthread -z muldefs
# Headers
DEPS = ./Edge.hpp ./Network.hpp \
	   ./Vertex.hpp 
# Object files

Dijkstras = ./Edge.o \
			./Vertex.o \
			./Network.o \
			./Driver.o


.PHONY : all
all : Dijkstras

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

Dijkstras: $(Dijkstras)
	$(CC) -o $@ $^

clean:
	$(RM) $(Dijkstras) ./Dijkstras 
