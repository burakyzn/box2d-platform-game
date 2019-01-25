#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "level.h"
#include <iostream>

int main() {
	bool levelOne = true;
	bool restart;
	
	do
	{
		level *levelPack = new level();
		levelPack->createLevelOne();
		levelOne = levelPack->levelOneUpdate();

		if (levelOne == false) {
			restart = levelPack->levelOneLose();
			delete levelPack;
		}
		else {
			levelOne = true;
			restart = false;
			break;
		}

	} while (restart);
	
	return 0;
}