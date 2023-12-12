build:
	gcc -std=c99 ./src/*.c ./src/screens/*.c -lraylib -lm -o raylib-jam

run:
	./raylib-jam

clean:
	rm ./raylib-jam
