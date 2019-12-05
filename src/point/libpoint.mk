CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../libs
LDFLAGS= -lm
INC= ../../include
EXEC= libpoint.a
SRC= point.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

point.o : point.c
	$(CC) $(CFLAGS)  -c point.c -I $(INC) -L $(LIB)

$(EXEC) : $(OBJ) $(INC)/point.h
	ar rcs $(LIB)/libpoint.a $(OBJ)
	ranlib $(LIB)/libpoint.a

clean:
	rm $(LIB)/libpoint.a point.o