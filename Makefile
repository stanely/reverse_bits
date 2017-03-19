CC = gcc
CFLAGS = -I.
DEPS = 
OBJ = reverse_bits.o
PROGRAM = reverse_bits.out

all: $(PROGRAM)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o $(PROGRAM)
