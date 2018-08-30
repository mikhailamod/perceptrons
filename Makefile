CC=g++
CFLAGS=-std=c++11 -Wall

SRCDIR=src
BUILDIR=build
BINDIR=bin

SOURCES:= src/main.cpp

OBJECTS:=$(patsubst $(SRCDIR)/%.cpp,$(BUILDIR)/%.o,$(SOURCES))
EXECUTBALE=pcd

all: $(EXECUTBALE)

$(EXECUTBALE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $(OBJECTS)

$(BUILDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -Iinclude/Eigen -c $< -o $@

clean:
	rm bin/$(EXECUTBALE)
	rm build/*.o

run:
	cd bin; ./$(EXECUTBALE)