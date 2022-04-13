SRC_DIR = ../../src
TEST_DIR  = ../../test/file_utils
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
OBJS = utest.o $(SRC_DIR)/file_utils.o 

$(TARGET):$(OBJS)

utest.o : $(INC_DIR)/file_utils.hpp 
$(SRC_DIR)/file_utils.o: $(INC_DIR)/file_utils.hpp


check: $(TARGET) book.txt
	./$(TARGET) -v

warnpeace:
	wget https://raw.githubusercontent.com/mmcky/nyu-econ-370/master/notebooks/data/book-war-and-peace.txt

book.txt: warnpeace
	 cat book-war-and-peace.txt| tr -d '[:punct:]' > book.txt

prod: CXXFLAGS += -O2 -DNDEBUG
prod: $(TARGET)
	./$(TARGET) -v

clean:
	@$(RM) $(TARGET) $(OBJS) book*

.PHONY: check clean
