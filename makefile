all: stats.c
	gcc stats.c -o stats
run: all
	./stats
