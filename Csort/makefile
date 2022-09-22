CC := clang

C_SRCS := $(wildcard *.c)
C_OBJS := $(patsubst %.c, %.o, $(C_SRCS))

TARGET := main

.PHONY: all clean run
all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(C_OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(TARGET) $(C_OBJS) stats.txt unsorted.txt