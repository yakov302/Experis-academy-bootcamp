
SRC_DIR = ../../test/bf
TEST_DIR  = ../../test/bf
INC_DIR = ../../test/bf

CXX = g++
CC = $(CXX)

WARNINGS = -pedantic
WARNINGS += -Wall -Werror

DEBUG = -g3
CXX_STD = c++17


CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD) $(LDLIBS)


CPPFLAGS = -I$(INC_DIR)

TARGET = utest
OBJS = ./utest.o 

$(TARGET):$(OBJS)

utest.o : 


check: $(TARGET)
	./$(TARGET) -v


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: check clean
