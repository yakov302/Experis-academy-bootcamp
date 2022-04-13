#SRC_DIR = ../../src
TEST_DIR  = ../../test/queue
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
OBJS = utest.o 

$(TARGET):$(OBJS)

utest.o : $(INC_DIR)/queue.hpp

check: $(TARGET)
	./$(TARGET) -v
	
clean:
	@$(RM) $(TARGET) $(OBJS)
	
.PHONY: check clean
