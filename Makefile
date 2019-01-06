CC=gcc
SOURCES=main.c lib.c
BIN=bin/main
FLAGS=-O2 -Wall

TEST_SOURCES=tests.c lib.c
TEST_BIN=bin/test

all:
	$(CC) $(SOURCES) -o $(BIN) $(FLAGS)

debug:
	$(CC) $(SOURCES) -o $(BIN) $(FLAGS) -g

checks:
	@grep -Hn TODO *.c

tests:
	@$(CC) $(TEST_SOURCES) -o $(TEST_BIN) $(FLAGS)
	@./$(TEST_BIN)
	@rm -rf $(TEST_BIN)

build: all checks

.PHONY: clean
clean:
	rm -rf $(BIN)
