CC = gcc
CFLAGS = $(shell pkg-config --cflags gtk+-3.0) -c -g -Wall -Wextra
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXE = gui

all: $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXE)
