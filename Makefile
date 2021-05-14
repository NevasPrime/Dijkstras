CC=g++
CPPFLAGS= -Wall -O2 
LINKFLAGS = -lpthread -z muldefs
# Headers
DEPS = ./src/Edge.hpp ./src/Network.hpp \
	   ./src/Vertex.hpp 

# Object files
Dijkstras = ./src/Edge.o \
			./src/Vertex.o \
			./src/Network.o \
			./src/Driver.o


.PHONY : all
all : Dijkstras

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

Dijkstras: $(Dijkstras)
	$(CC) -o $@ $^

clean:
	$(RM) $(Dijkstras) ./Dijkstras 
