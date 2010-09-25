CC=gcc
CFLAGS=
LD=gcc
LDFLAGS=-lSDL
# -lSDL_mixer

EXEC=lew
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)

$(EXEC): $(OBJECTS)
	$(LD) $(LDFLAGS) $< -o $@

.o:
	$(CC) $(CFLAGS) $< -o $@
