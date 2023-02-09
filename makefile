all: 
	g++ src/*.cpp -Iinclude -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o survivalRun  && ./survivalRun
