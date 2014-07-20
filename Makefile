CC = gcc
CXX = g++

CFLAGS = -c

LDFLAGS = $(shell pkg-config --libs libtorrent-rasterbar)

all:
	$(MAKE) -C core

test: all
	$(CC) $(CFLAGS) test.c -o test.o
	$(CXX) test.o gtorrent-c.a -o test $(LDFLAGS)

clean:
	$(MAKE) -C core clean
	rm test test.o
