SRC_DIR = ../../src
TEST_DIR  = ../../test/single_list
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
OBJS = utest.o $(SRC_DIR)/single_list.o $(SRC_DIR)/utils.o $(SRC_DIR)/hash_set.o  $(SRC_DIR)/ball.o 

$(TARGET):$(OBJS)

$(SRC_DIR)/utils.o: $(INC_DIR)/single_list.hpp
$(SRC_DIR)/single_list.o: $(INC_DIR)/single_list.hpp $(INC_DIR)/hash_set.hpp
utest.o: $(INC_DIR)/single_list.hpp $(INC_DIR)/ball.hpp
$(SRC_DIR)/hash_set.o: $(INC_DIR)/hash_set.hpp
 $(SRC_DIR)/ball.o : $(INC_DIR)/ball.hpp


check: $(TARGET)
	./$(TARGET) -v
	
clean:
	@$(RM) $(TARGET) $(OBJS)
	
.PHONY: check clean
