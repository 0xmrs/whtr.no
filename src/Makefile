CC=cc
CFLAGS=-Wall --std=c17

debug: CFLAGS += -g
debug: whtr.no

DEPEND=url.h met-data-fetcher.h nowcast-formatter.h locationforecast-formatter.h degrees-to-compass-diretions.h utils.h

LIB=-lcurl -ljson-c -lm

OBJDIR=./obj

_OBJ=url.o met-data-fetcher.o main.o nowcast-formatter.o locationforecast-formatter.o degrees-to-compass-diretions.o utils.o
OBJ=$(patsubst %,$(OBJDIR)/%,$(_OBJ))

$(OBJDIR)/%.o: %.c $(DEPEND)
	$(CC) $(CFLAGS) $< -c -o $@

whtr.no: $(OBJ)
	$(CC) $(LIB) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o
