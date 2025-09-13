CC = gcc
SRC = ./src
INCLUDES = ./includes

ifeq ($(OS),Windows_NT)
    RM = del /Q /F
    OUTPUT = build\cold.exe
    MKDIR = if not exist build mkdir build
else ifeq ($(shell uname -s),Linux)
    RM = rm -f
    OUTPUT = build/cold
    MKDIR = mkdir -p build
endif

all: $(OUTPUT)

$(OUTPUT): $(SRC)/*.c | build
	$(CC) $^ -I$(INCLUDES) -o $@

build:
	$(MKDIR)

clean:
	$(RM) $(OUTPUT)
	@echo Build directoy cleaned