CC=g++
CFLAGS=-std=c++11 -Wall

SRCDIR=src
BUILDIR=build
BINDIR=bin

SOURCES:= src/main.cpp

OBJECTS:=$(patsubst $(SRCDIR)/%.cpp,$(BUILDIR)/%.o,$(SOURCES))
EXECUTBALE=perceptrons

all: $(EXECUTBALE)

$(EXECUTBALE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $(OBJECTS)

$(BUILDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm bin/$(EXECUTBALE)
	rm build/*.o

run:
	cd bin; ./$(EXECUTBALE)