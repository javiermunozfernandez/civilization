
vpath %.c src

RM       := rm -f
RMDIR    := rm -rf

CC       := gcc
CFLAGS   := -std=c17 -Wall -Wextra -Wpedantic -O0 -ggdb3 -fanalyzer
CPPFLAGS := -D_REENTRANT
LDLIBS   := -pthread -lSDL2

TARGET   := civilization

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) -o $@ $(LOADLIBES) $(LDLIBS) $^

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $^

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
