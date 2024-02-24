build:
	g++ ./src/*.cpp -Wall -std=c++17 -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -llua5.3 -I "./libs"
run:
	./a.out
clean:
	rm ./a.out