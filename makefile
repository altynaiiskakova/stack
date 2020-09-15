
TARGET = teststack
OBJ    = stack.o teststack.o


CC     = gcc
CFLAGS = -std=c99 -Wall -pedantic

%.o: %.c %.h
	$(CC) $(CFLAGS) $< -c

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@



clean:
	$(RM) $(RMFLAGS) $(TARGET) $(OBJ)
