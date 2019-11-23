CC=gcc
CFLAGS=-W -Wall -utf8 -pedantic
LDFLAGS=
EXEC=main lorentz

start: $(EXEC)

main: main.c main.h
	$(CC) -o $@ -c $< $(CFLAGS)
	
lorentz: lorentz.c lorentz.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)