SRC_DIR = ../../src
TEST_DIR  = ../../test/quick_sort
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
OBJS = utest.o  $(SRC_DIR)/ball.o  $(SRC_DIR)/utils.o

$(TARGET):$(OBJS)

utest.o : $(INC_DIR)/quick_sort.hpp $(INC_DIR)/ball.hpp $(INC_DIR)/utils.hpp
$(SRC_DIR)/ball.o: $(INC_DIR)/ball.hpp
$(SRC_DIR)/utils.o: $(INC_DIR)/utils.hpp

check: $(TARGET)
	./$(TARGET) -v

prod: CXXFLAGS += -O2 -DNDEBUG
prod: $(TARGET)
	./$(TARGET) -v

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: check clean
