CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../libs
LDFLAGS= -lm  -lpoint
INC= ../../include
EXEC= liblorenz.a
SRC= lorenz.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

lorenz.o : lorenz.c
	$(CC) $(CFLAGS)  -c lorenz.c $(LDFLAGS) -I $(INC) -L $(LIB)

$(EXEC) : $(OBJ) $(INC)/lorenz.h
	ar rcs $(LIB)/liblorenz.a $(OBJ)
	ranlib $(LIB)/liblorenz.a

clean:
	rm $(LIB)/liblorenz.a lorenz.o
