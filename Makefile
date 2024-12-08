CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = enigma

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
    rm -f $(OBJS) $(TARGET)
