SRC_DIR = ../../src
TEST_DIR  = ../../test/big_integer
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
OBJS = utest.o $(SRC_DIR)/big_integer.o $(SRC_DIR)/utils.o $(SRC_DIR)/single_list.o $(SRC_DIR)/hash_set.o 

$(TARGET):$(OBJS)

$(SRC_DIR)/utils.o: $(INC_DIR)/big_integer.hpp
$(SRC_DIR)/single_list.o: $(INC_DIR)/single_list.hpp $(INC_DIR)/hash_set.hpp
$(SRC_DIR)/big_integer.o: $(INC_DIR)/big_integer.hpp
utest.o: $(INC_DIR)/single_list.hpp
$(SRC_DIR)/hash_set.o: $(INC_DIR)/hash_set.hpp

vala: $(TARGET)
	valgrind --log-file=V1.log ./$(TARGET)
	valgrind --log-file=V2.log --leak-check=full --track-origins=yes ./$(TARGET) 
   
check: $(TARGET)
	./$(TARGET) -v
	
clean:
	@$(RM) $(TARGET) $(OBJS)
	
.PHONY: check clean
