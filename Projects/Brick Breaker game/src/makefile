
SRC_DIR = ../src
#TEST_DIR  = ../../brick_breaker/main
INC_DIR = ../inc

CXX = g++
CC = $(CXX)

WARNINGS = -pedantic
WARNINGS += -Wall -Werror

DEBUG = -g3
CXX_STD = c++17

LDLIBS   = -lsfml-graphics -lsfml-window -lsfml-system  -lsfml-audio

CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD) $(LDLIBS)


CPPFLAGS = -I$(INC_DIR)

TARGET = main
OBJS = ./main.o  ./ball.o ./level.o ./rec.o ./game.o ./level_loader.o ./padel.o ./brick.o ./collision.o

$(TARGET):$(OBJS)

./main.o : $(INC_DIR)/game.hpp
./ball.o : $(INC_DIR)/ball.hpp 
./game.o : $(INC_DIR)/level.hpp
./rec.o: $(INC_DIR)/rec.hpp 
./game.o: $(INC_DIR)/game.hpp
./level_loader: $(INC_DIR)/level_loader.hpp
./padel.o: $(INC_DIR)/padel.hpp
./brick.o: $(INC_DIR)/brick.hpp
./collision.o: $(INC_DIR)/collision.hpp

check: $(TARGET)
	./$(TARGET) -v  


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: check clean
