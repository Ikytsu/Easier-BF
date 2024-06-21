GPLUS=g++

SRC=src/main.cpp
OBJ=$(SRC:.c=.o)
EXEC=bin/ebf

all: $(EXEC)

$(EXEC): $(OBJ)
	$(GPLUS) -o $@ $^

%.o: %.c
	$(GPLUS) -o $@ $<

clear:
	rm -f $(OBJ) $(EXEC)
