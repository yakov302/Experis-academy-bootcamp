
SRC_DIR = ../src
TEST_DIR  = ../test/thread
INC_DIR = ../inc

CXX = g++
CC = $(CXX)

WARNINGS = -pedantic
WARNINGS += -Wall -Werror

DEBUG = -g3
CXX_STD = c++17

LDLIBS   = -lpthread

CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD) $(LDLIBS)


CPPFLAGS = -I$(INC_DIR)

TARGET = utest
OBJS = utest.o $(SRC_DIR)/utils.o 

$(TARGET):$(OBJS)

utest.o : $(INC_DIR)/thread.hpp $(INC_DIR)/blocking_queue.hpp $(INC_DIR)/mutex.hpp 


check: $(TARGET)
	./$(TARGET) -v

vala: $(TARGET)
	valgrind --leak-check=full --track-origins=yes --log-file=logValgrind01.txt ./$(TARGET)
	valgrind --tool=helgrind --log-file=loghelgrind01.txt ./$(TARGET)
	valgrind --tool=drd --log-file=logdrd01.txt ./$(TARGET)

prod: CXXFLAGS += -O2 -DNDEBUG
prod: $(TARGET)
	./$(TARGET) -v

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: check clean
