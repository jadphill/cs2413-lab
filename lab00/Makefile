CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -O2

TARGET = lab00_demo
SRC = src/main.c

.PHONY: all run clean

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
