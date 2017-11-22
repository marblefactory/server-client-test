CC     = g++
CFLAGS = -std=c++11 -w
LINKER = -lboost_system -lpthread

SRC_DIR = src
LOGGER = $(SRC_DIR)/logger.cpp
CLIENT = $(LOGGER) $(SRC_DIR)/client.cpp
MAIN   = $(CLIENT) $(SRC_DIR)/main.cpp

BIN_DIR = bin
OUTPUT_NAME = $(BIN_DIR)/client.out

bcli:
	$(CC) $(CFLAGS) $(MAIN) -o $(OUTPUT_NAME) $(LINKER)
clean:
	rm $(BIN_DIR)/*.out
