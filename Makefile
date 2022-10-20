CC = g++
CFLAGS = -Wall
LDFLAGS = 
SOURCES = main.cpp maze.cpp
OBJ = $(SOURCES:.cpp=.o)
EXECUTABLE = maze

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) 
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.cpp.o:  
	$(CC) $(CFLAGS) $< -c $@ 

clean: 
	rm -f *.o $(EXECUTABLE)
