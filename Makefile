
APP = "pong"

build:
	export LD_LIBRARY_PATH=/usr/local/SFML/lib
	g++ -std=c++17 -o $(APP) $(APP).cpp -I/usr/local/SFML/include -L/usr/local/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lfreetype

run:
	./$(APP)

all:
	make build
	make run

build2:
	g++ -Wall -g -o main main.cpp -lncurses

build3:
	export LD_LIBRARY_PATH=/usr/local/SFML/lib
	g++ -std=c++17 -o main2 main2.cpp -I/usr/local/SFML/include -L/usr/local/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lfreetype

.PHONY: build run build2 build3 all

