all:
	gcc -c Main.c -lmingw32 -lSDL2main -lSDL2 -O3 -flto
	gcc -c rendering/render.c -lmingw32 -lSDL2main -lSDL2 -O3 -flto
	gcc -c map/map.c -lmingw32 -lSDL2main -lSDL2 -O3 -flto
	gcc -c dependencies/vectormath.c -lmingw32 -lSDL2main -lSDL2 -O3 -flto
	gcc -c physics/physics.c -lmingw32 -lSDL2main -lSDL2 -O3 -flto
	gcc -c physics/phyDep/PushPhysics.c -lmingw32 -lSDL2main -lSDL2 -O3 -flto
		gcc -c physics/phyDep/Expand.c -lmingw32 -lSDL2main -lSDL2 -O3 -flto
	gcc main.o render.o map.o vectormath.o physics.o Expand.o PushPhysics.o dependencies/struct.h -lmingw32 -lSDL2main -lSDL2  -static-libgcc -O3 -flto 