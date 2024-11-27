CC = gcc
CFLAGS = -Wall -g

SRCS = main.c reminder.c linked_list.c interact.c
OBJS = $(SRCS:.c=.o)
TARGET = gcal

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
