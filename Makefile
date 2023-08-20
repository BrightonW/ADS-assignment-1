CC = gcc
CFLAGS = -Wall

# define libraries to be linked (for example -lm)
LIB = 


HDR = array.h data.h
SRC = main.c array.c data.c 

# OBJ is the same as SRC, just sustitute ".c" with ".o"
OBJ     = $(SRC:.c=.o)

# the executable name
EXE = dict1


$(EXE): $(HDR) $(OBJ) Makefile
	echo $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(LIB)


clean: 
	rm -f $(OBJ) $(EXE)

$(OBJ): $(HDR)
