SRC_DIR = ../../src
TEST_DIR  = ../../test/rational
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
OBJS = utest.o $(SRC_DIR)/rational.o $(SRC_DIR)/utils.o 

$(TARGET):$(OBJS)

utest.o: $(INC_DIR)/rational.hpp
$(SRC_DIR)/stack.o: $(INC_DIR)/rational.hpp $(INC_DIR)/utils.hpp
$(SRC_DIR)/utils.o: $(INC_DIR)/utils.hpp


check: $(TARGET)
	./$(TARGET) -v
	
clean:
	@$(RM) $(TARGET) $(OBJS)
	
.PHONY: check clean
