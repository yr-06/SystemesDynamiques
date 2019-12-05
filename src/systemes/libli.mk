CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../libs
LDFLAGS= -lm -lpoint 
INC= ../../include
EXEC= libli.a
SRC= li.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

li.o : li.c
	$(CC) $(CFLAGS)  -c li.c -I $(INC) -L $(LIB)

$(EXEC) : $(OBJ) $(INC)/li.h
	ar rcs $(LIB)/libli.a $(OBJ)
	ranlib $(LIB)/libli.a

clean:
	rm $(LIB)/libli.a li.o
