# Initializing variables
CC = gcc
CFLAGS = -Wall -Wextra -fPIC -O2 -std=c99
LDFLAGS = -lSTL_String -lSTL_Vector

# Main part
all: main libs hashmap
	$(CC) $(CFLAGS) src/build/main.o src/libs/build/libs.o src/libs/build/hash_map.o -o ./main $(LDFLAGS)

main: src/main.c
	mkdir -p src/build
	$(CC) $(CFLAGS) -c src/main.c -o src/build/main.o

libs: src/libs/libs.c src/libs/libs.h
	mkdir -p src/libs/build
	$(CC) $(CFLAGS) -c src/libs/libs.c -o src/libs/build/libs.o

hashmap: src/libs/hash_map.c src/libs/hash_map.h
	$(CC) $(CFLAGS) -c src/libs/hash_map.c -o src/libs/build/hash_map.o

clean:
	rm -rf *.o ./main
	rm -rf src/build src/libs/build
