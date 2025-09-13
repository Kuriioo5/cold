CC = gcc
SRC = ./src
BIN = ./bin
INCLUDES = ./includes

build:
	$(CC) $(SRC)/*.c -I$(INCLUDES) -o $(BIN)/cold

run:
	$(BIN)/cold

all: build run