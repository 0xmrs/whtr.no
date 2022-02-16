CC=gcc
CFLAGS=-Wall

BIN=met-data

LIB=-lcurl

all:
	$(CC) $(CFLAGS) $(LIB) url.c met-data-fetcher.c main.c -o $(BIN)
clean:
	rm -rf $(BIN)
