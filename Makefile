## CS134 Spring 2014: Video Game Design
## Lab Ogre3D Makefile
##
## This file does not need to be modified
#########################################

OGRE_PREFIX = /usr/csshare/pkgs
INCLUDE_PATHS = -I $(OGRE_PREFIX)/ogre-1.8.1/include/OGRE/ -I $(OGRE_PREFIX)/ois-v1-3/includes/
LIB_PATHS = -L $(OGRE_PREFIX)/ogre-1.8.1/lib/ -L $(OGRE_PREFIX)/ogre-1.8.1/lib/OGRE/ -L $(OGRE_PREFIX)/ois-v1-3/lib/
LIBS = -lOgreMain -lOIS
CC = g++ -ggdb -O3

## Global header files
INCLUDE = const.h

## Object files and executables
MAIN_OUT = a.out
BASE_APPLICATION_OUT = BaseApplication.o
PLAYER_OUT = Player.o
ENEMY_OUT = Enemy.o
ITEM_OUT = Item.o
PROJECTILE_OUT = Projectile.o

## Requirements for each command
MAIN_REQS = MainApplication.cpp $(BASE_APPLICATION_OUT) $(PROJECTILE_OUT) $(PLAYER_OUT) $(ENEMY_OUT) $(ITEM_OUT)
BASE_APPLICATION_REQS = BaseApplication.h BaseApplication.cpp
PLAYER_REQS = GameEntity.h $(PROJECTILE_OUT) Player.h Player.cpp
ENEMY_REQS = GameEntity.h $(PROJECTILE_OUT) Enemy.h Enemy.cpp
ITEM_REQS = GameEntity.h Item.h Item.cpp
PROJECTILE_REQS = GameEntity.h Projectile.h Projectile.cpp


## Targets to compile for each command
MAIN_TARGETS = MainApplication.cpp $(BASE_APPLICATION_OUT) $(PROJECTILE_OUT) $(PLAYER_OUT) $(ENEMY_OUT)
BASE_APPLICATION_TARGETS = BaseApplication.cpp
PLAYER_TARGETS = Player.cpp
ENEMY_TARGETS = Enemy.cpp
ITEM_TARGETS = Item.cpp
PROJECTILE_TARGETS = Projectile.cpp

all: main

## Main
main: $(MAIN_REQS) $(INCLUDE)
	$(CC) $(INCLUDE_PATHS) $(LIB_PATHS) $(MAIN_TARGETS) $(LIBS) -o $(MAIN_OUT)
$(BASE_APPLICATION_OUT): $(BASE_APPLICATION_REQS) $(INCLUDE)
	$(CC) -c $(INCLUDE_PATHS) $(LIB_PATHS) $(BASE_APPLICATION_TARGETS) $(LIBS) -o $(BASE_APPLICATION_OUT)
$(PLAYER_OUT): $(PLAYER_REQS) $(INCLUDE)
	$(CC) -c $(INCLUDE_PATHS) $(PLAYER_TARGETS) -o $(PLAYER_OUT)
$(ENEMY_OUT): $(ENEMY_REQS) $(INCLUDE)
	$(CC) -c $(INCLUDE_PATHS) $(ENEMY_TARGETS) -o $(ENEMY_OUT)
$(PROJECTILE_OUT): $(PROJECTILE_REQS) $(INCLUDE)
	$(CC) -c $(INCLUDE_PATHS) $(PROJECTILE_TARGETS) -o $(PROJECTILE_OUT)
$(ITEM_OUT): $(ITEM_REQS) $(INCLUDE)
	$(CC) -c $(INCLUDE_PATHS) $(ITEM_TARGETS) -o $(ITEM_OUT)
clean:
	rm -f *~ *.o *.out
