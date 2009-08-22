DIR = /Users/raichoo/Projects/SakuraCore
INC = $(DIR)/include 
LIB = $(DIR)/build
DEBUG = -DDEBUG
CC = llvm-g++
CXXFLAGS = $(DEBUG) -O2 -g -ansi -pedantic -std=c++98

all: main.cpp
	$(CC) $(CXXFLAGS) -I$(INC) -L$(LIB) -l SakuraCore $< -o main 

clean: 
	rm main 
