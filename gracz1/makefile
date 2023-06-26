CC=gcc
CFLAGS=-lpthread
SOURCES=player.c load_status.c map.c train.c move.c attack.c save.c mining.c

all: player run

player: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o player

run:
	./player mapa.txt status.txt rozkazy.txt 2
clean:
	rm *player
