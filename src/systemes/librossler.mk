CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../libs
LDFLAGS= -lm -lpoint 
INC= ../../include
EXEC= librossler.a
SRC= rossler.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

rossler.o : rossler.c
	$(CC) $(CFLAGS)  -c rossler.c -I $(INC) -L $(LIB)

$(EXEC) : $(OBJ) $(INC)/rossler.h
	ar rcs $(LIB)/librossler.a $(OBJ)
	ranlib $(LIB)/librossler.a

clean:
	rm $(LIB)/librossler.a rossler.o
