CC= gcc
CFLAGS= -Wall -g #-std=c11 -lm
LIB= ../libs
LDFLAGS= -lpoint -lli -lrossler -llorenz -lm
INC= ../include
EXEC= main.exe
SRC= main.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : main.c
	$(CC) $< -o $@ $(CFLAGS) $(LDFLAGS) -I $(INC) -L $(LIB)

clean:
	rm *.exe *.o