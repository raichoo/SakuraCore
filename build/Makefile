OBJ = AbstractClass.o AbstractFunctor.o Application.o GarbageCollector.o Message.o Object.o RTTI.o AbstractLock.o IMonitor.o Spinlock.o AbstractType.o LexicalType.o NumericalType.o Process.o
DIR = /Users/raichoo/Projects/SakuraCore
INC = $(DIR)/include 
SRC = $(DIR)/src

DEBUG = -DDEBUG
CC = llvm-g++
CXXFLAGS = $(DEBUG) -DLIBRARY -c -O2 -g -ansi -pedantic -std=c++98
LDFLAGS = -dynamiclib

TARGET = libSakuraCore.dylib

all: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(TARGET) 

AbstractClass.o: $(SRC)/Core/AbstractClass.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $< 
AbstractFunctor.o: $(SRC)/Core/AbstractFunctor.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $< 
Application.o: $(SRC)/Core/Application.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
GarbageCollector.o: $(SRC)/Core/GarbageCollector.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
Message.o: $(SRC)/Core/Message.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
Object.o: $(SRC)/Core/Object.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
RTTI.o: $(SRC)/Core/RTTI.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
AbstractLock.o: $(SRC)/Core/Threading/AbstractLock.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
IMonitor.o: $(SRC)/Core/Threading/IMonitor.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
Spinlock.o: $(SRC)/Core/Threading/Spinlock.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
AbstractType.o: $(SRC)/Core/Types/AbstractType.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
LexicalType.o: $(SRC)/Core/Types/LexicalType.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
NumericalType.o: $(SRC)/Core/Types/NumericalType.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<
Process.o: $(SRC)/Core/Process.cpp
	$(CC) $(CXXFLAGS) -I$(INC) $<

clean: 
	rm $(TARGET) $(OBJ) 

