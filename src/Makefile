CC=clang
CFLAGS=-Wall

SRC=url.c met-data-fetcher.c main.c  nowcast-formatter.c locationforecast-formatter.c degrees-to-compass-diretions.c
OBJS=url.o met-data-fetcher.o main.o nowcast-formatter.o locationforecast-formatter.o degrees-to-compass-diretions.o

LIB=-lcurl -ljson-c -lm

all: met-data

met-data: $(OBJS)
	$(CC) $(LIB) $(CFLAGS) -o met-data $(OBJS)

clean:
	rm -f $(OBJS) met-data
