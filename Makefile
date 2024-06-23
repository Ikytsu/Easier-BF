GPLUS=g++

SRC=src/main.cpp src/load-config.cpp src/generate-c-code.cpp
OBJ=$(SRC:.c=.o)
EXEC=bin/ebf

all: $(EXEC)

$(EXEC): $(OBJ)
	$(GPLUS) -o $@ $^

%.o: %.c
	$(GPLUS) -o $@ $<

clear:
	rm -f $(OBJ) $(EXEC)
