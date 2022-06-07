.PHONY: build
build:
	g++ -Wall -g -o main main.cpp -lncurses

.PHONY: build2
build2:
	# g++ -std=c++17 -Wall -g -o main2 main2.cpp -I/usr/local/SFML/include -L/usr/local/SFML/build/lib -lsfml-system -lsfml-graphics -lsfml-window -lsfml-system
	g++ -std=c++17 -o main2 main2.cpp -I/usr/local/SFML/include -L/usr/local/SFML/build/lib -L/usr/local/lib64/ -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -DSFML_STATIC