###############################################################
## Declaring Makefile Vars ####################################
###############################################################

CC = g++
LANG_STD = -std=c++17
SOURCE_FILES = ./src/*.cpp ./src/Game/*.cpp ./src/Logger/*.cpp
C_FLAGS = -Wall -Wfatal-errors 
L_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -llua5.3
INCLUDE = -I "./libs"
APP_NAME = gameengine
OUTPUT_FILE = -o $(APP_NAME)


build:
	$(CC) $(SOURCE_FILES) $(C_FLAGS) $(LANG_STD) $(L_FLAGS) $(INCLUDE) $(OUTPUT_FILE)
run:
	./$(APP_NAME)	
clean:
	rm ./$(APP_NAME)