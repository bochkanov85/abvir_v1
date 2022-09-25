GCC_PATH=c:\\MinGW\bin

CC=$(GCC_PATH)\\gcc

WINDRES=$(GCC_PATH)\\windres

LIBS=-lpsapi

SRC_FILES = main.c \
			process_proc.c

all: abvir_v1

abvir_v1: $(SRC_FILES)
	$(WINDRES) -o abvir_v1.o abvir_v1.rc
	$(CC) -o abvir_v1 $(SRC_FILES) abvir_v1.o $(LIBS)

clean:
	rm -f *.exe
	rm -f *.o