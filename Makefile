CC := g++
CFLAGS := -std=c++17 -Wall -Wextra -g

OBJS := mainbst.o bst.o customErrorClass.o
DEPS := bst.h customErrorClass.h

.PHONY: all clean

all: bst

bst: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

mainbst.o: mainbst.cpp $(DEPS)
	$(CC) -c -o $@ $(CFLAGS) $<

bst.o: bst.cpp $(DEPS)
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp customErrorClass.h
	$(CC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f $(OBJS) bst