CC     = g++
CFLAGS = -std=c++11 -w
LINKER = -lboost_system -lpthread

SRC_DIR = src
SERVER = $(SRC_DIR)/server.cpp
MAIN   = $(SERVER) $(SRC_DIR)/main.cpp

BIN_DIR = bin
OUTPUT_NAME = $(BIN_DIR)/server

bcli:
	$(CC) $(CFLAGS) $(MAIN) -o $(OUTPUT_NAME) $(LINKER)
clean:
	rm $(BIN_DIR)/*
