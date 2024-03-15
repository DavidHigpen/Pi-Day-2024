CC = g++
CFLAGS = -Wall -Wextra -g

TARGET = pi

$(TARGET): pi.cpp
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean: 
	rm -f $(TARGET)