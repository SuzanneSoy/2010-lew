CC=gcc
CFLAGS=
LD=gcc
LDFLAGS=-lSDL
# -lSDL_mixer
RM=rm

EXEC=lew
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)

.Phony: all
all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(LD) $(LDFLAGS) $< -o $@

.o:
	$(CC) $(CFLAGS) $< -o $@

.Phony: clean
clean:
	$(RM) $(OBJECTS)

.Phony: mrproper
mrproper: clean
	$(RM) $(EXEC)

.Phony: test
test: $(EXEC)
	-./$(EXEC)
