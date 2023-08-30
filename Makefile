CC := c++
RM := rm -f

TARGET := ./fp

CLASSES := Fp.hpp Fixed.hpp

SRCS := main.cpp Fp.cpp Fixed.cpp
OBJS := $(SRCS:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(SRCS) $(CLASSES)
	$(CC) $(SRCS) -std=c++11 -o $@

clean:
	$(RM) $(TARGET)
re: clean all

.PHONY: all clean re
.INTERMEDIATE: $(OBJS)