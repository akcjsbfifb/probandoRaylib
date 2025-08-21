CC       := gcc
CFLAGS   := -Wall -g
BIN      := juego
LFLAGS   := -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

SRC      := main.c   # agregá tus archivos .c aquí
DEPS     :=       # agregá tus headers aquí
OBJ      := $(SRC:.c=.o)

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)

.PHONY: all clean

