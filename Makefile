CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = mypreprocessor

SOURCES = main.c comment_removal.c file_inclusion.c macro_handler.c

OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) *.i
