
SRC_DIR = ../../test/bf
TEST_DIR  = ../../test/bf
INC_DIR = ../inc

CXX = g++
CC = $(CXX)

WARNINGS = -pedantic
WARNINGS += -Wall -Werror

DEBUG = -g3
CXX_STD = c++17


CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD) $(LDLIBS)


CPPFLAGS = -I$(INC_DIR)

TARGET = main
OBJS = ./main.o ./word_matrix.o ./fill_container.o ./word_frequency.o 

$(TARGET):$(OBJS)

main.o : $(INC_DIR)/mu_test.h $(INC_DIR)/word_matrix.hpp
word_matrix.o: $(INC_DIR)/word_matrix.hpp
fill_container.o:  $(INC_DIR)/fill_container.hpp $(INC_DIR)/matrix.hpp
word_frequency.o: $(INC_DIR)/word_frequency.hpp


check: $(TARGET)
	./$(TARGET) -v


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: check clean
