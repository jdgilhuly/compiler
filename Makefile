CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
SRCS = src/main.cpp src/lexer.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = compiler

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean