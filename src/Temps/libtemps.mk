CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../libs
LDFLAGS= -lm  -lpoint
INC= ../../include
EXEC= libtemps.a
SRC= temps.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

temps.o : temps.c
	$(CC) $(CFLAGS)  -c temps.c $(LDFLAGS) -I $(INC) -L $(LIB)

$(EXEC) : $(OBJ) $(INC)/temps.h
	ar rcs $(LIB)/libtemps.a $(OBJ)
	ranlib $(LIB)/libtemps.a

clean:
	rm $(LIB)/libtemps.a temps.o
