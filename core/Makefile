CXX = g++
CXXFLAGS = -std=c++11 -g -c -Wall -include all.h

SRC = Core.cpp Core-Wrapper.cpp Log.cpp Torrent.cpp
OBJ = $(SRC:.cpp=.o)
LIB = ../gtorrent-c.a

CXXFLAGS += $(shell pkg-config --cflags libtorrent-rasterbar)

all: $(SRC) $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $(OBJ)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(LIB)
