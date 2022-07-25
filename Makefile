CC = gcc
CFLAGS = -g -Wall
OBJS = main.o
TARGET = add-nbo

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	rm *.o

main.o: main.c

clean:
	rm -rf *.o $(TARGET)

