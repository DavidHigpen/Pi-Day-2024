
CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = pi

SRCS = pi.cpp piFunctions.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = piFunctions.h

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
