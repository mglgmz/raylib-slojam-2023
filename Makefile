PROJECT_SOURCE_FILES ?= utils.c player.c entity_list.c game_ui.c simulation.c particles.c space.c screens/gameplay.c screens/intro.c screens/logo.c screens/menu.c screens/options.c screens/score.c screens/screens.c raylib_game.c  

build:	
	gcc -std=c99 ./src/*.c ./src/screens/*.c -lraylib -lm -o as73roids

run:
	./as73roids

clean:
	rm ./as73roids
