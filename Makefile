GCC_PATH=c:\\MinGW\bin\\

CC=$(GCC_PATH)\\gcc

all: abvir_v1

abvir_v1: main.c
	$(CC) main.c -o abvir_v1

clean:
	rm -f *.exe