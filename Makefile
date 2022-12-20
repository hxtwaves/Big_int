.PHONY: all clean install uninstall

CC=g++
CFLAGS=-c 
LDFLAGS=
SOURCES=big_int.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
PREFIX = 

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)	
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf main *.o
install:
	install $(EXECUTABLE) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(EXECUTABLE)