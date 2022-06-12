
APP = "pong"

build:
	export LD_LIBRARY_PATH=/usr/local/SFML/lib
	g++ -std=c++17 -Ofast -o $(APP) $(APP).cpp Actors/ball.cpp Actors/paddle.cpp Actors/wall.cpp Game/game.cpp -I/usr/local/SFML/include -L/usr/local/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lfreetype

run:
	./$(APP)

all:
	make build
	make run

clean:
	rm $(APP)

.PHONY: build run clean all

