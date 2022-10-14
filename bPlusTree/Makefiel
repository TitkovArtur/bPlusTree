# @Author: Artur Titkov <Artur>
# @Date:   2020-09-07T21:26:45+02:00
# @Last modified by:   Artur
# @Last modified time: 2021-11-01T15:25:33+01:00

OS := $(shell uname)
ifeq ($(OS),Darwin)
	CC	= /usr/bin/g++
        CFLAGS  = -c -W -Wall -O -mavx -std=c++14 -w -march=native
       	LDFLAGS =
else
        CC      = g++
        CFLAGS  = -c -W -Wall -mavx -std=c++14 -w -march=native
        LDFLAGS =
endif

SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: btree

btree: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o run_btree $(LDADD)


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf *.exec
