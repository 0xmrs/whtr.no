CC=gcc
CFLAGS=-Wall

SRC=url.c met-data-fetcher.c main.c  
OBJS=url.o met-data-fetcher.o main.o

LIB=-lcurl

all: met-data

met-data: $(OBJS)
	$(CC) $(LIB) $(CFLAGS) -o met-data $(OBJS)

clean:
	rm -rf *.o
