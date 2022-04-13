SRC_DIR = ../../src
TEST_DIR  = ../../test/min_stack
INC_DIR = ../../inc

CXX = g++
CC = $(CXX)

WARNINGS = -pedantic
WARNINGS += -Wall -Werror

DEBUG = -g3
CXX_STD = c++03

CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD)

CPPFLAGS = -I$(INC_DIR)

TARGET = utest
OBJS = utest.o $(SRC_DIR)/min_stack.o $(SRC_DIR)/utils.o $(SRC_DIR)/stack.o

$(TARGET):$(OBJS)

$(SRC_DIR)/utils.o: $(INC_DIR)/utils.hpp
$(SRC_DIR)/stack.o: $(INC_DIR)/stack.hpp
$(SRC_DIR)/wonder_queue.o: $(INC_DIR)/min_stack.hpp  $(INC_DIR)/utils.hpp $(INC_DIR)/stack.hpp
utest.o: $(INC_DIR)/min_stack.hpp


check: $(TARGET)
	./$(TARGET) -v
	
clean:
	@$(RM) $(TARGET) $(OBJS)
	
.PHONY: check clean
