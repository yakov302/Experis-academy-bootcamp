SRC_DIR = ../../src
TEST_DIR  = ../../test/sorted_containers
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
OBJS = utest.o $(SRC_DIR)/utils.o $(SRC_DIR)/ball.o 

$(TARGET):$(OBJS)

utest.o : $(INC_DIR)/sorted_vector.hpp  $(INC_DIR)/sorted_container.hpp $(INC_DIR)/sorted_list.hpp $(INC_DIR)/ball.hpp  $(INC_DIR)/sorted_unique_list.hpp $(INC_DIR)/sorted_unique_vector.hpp 


check: $(TARGET)
	./$(TARGET) -v

prod: CXXFLAGS += -O2 -DNDEBUG
prod: $(TARGET)
	./$(TARGET) -v

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: check clean
