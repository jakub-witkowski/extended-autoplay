CC=gcc
CFLAGS=-lpthread
SOURCES=player.c load_status.c menu.c map.c display_map.c list.c train.c move.c attack.c save.c mining.c

all: player run

player: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o ../g1

run:
	../g1 mapa.txt status.txt rozkazy.txt 10
clean:
	rm *player
