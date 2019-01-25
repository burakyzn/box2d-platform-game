#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "player.h"
class animation
{
private:
	int idleCont;
	int runCont;
	int coinCont;
	int waterCont;

	sf::Texture	textureIdleRIGHT[11];
	sf::Texture	textureIdleLEFT[11];
	sf::Texture textureRunLEFT[13];
	sf::Texture textureRunRIGHT[13];
	sf::Texture textureJumpLEFT[2];
	sf::Texture textureJumpRIGHT[2];
	///////////////////////////
	sf::Texture coinText[16];
	sf::Sprite *coinSprite;
	const int coinSpriteCon = 5;
	//////////////////////////
	sf::Texture waterText[17];
	sf::Sprite *waterSprite;
	const int waterSpriteCon = 13;
	//////////////////////////
	sf::Sprite *playerSprite;
	//////////////////////////
	sf::Clock clockCoin;
	sf::Clock clockWater;
	sf::Clock clockYon;
	sf::Clock clockJump;
	sf::Clock clockRun;

public:
	bool isPlayerOnAir;
public:
	animation();
	void setupSprite(sf::Sprite *karakterSprite, sf::Sprite coinSprite[], sf::Sprite waterSprite[]);
	void setupText(sf::Texture textureIdleLEFT[], sf::Texture textureIdleRIGHT[],
		sf::Texture texttureRunLEFT[], sf::Texture texttureRunRIGHT[], sf::Texture texttureJumpLEFT[], sf::Texture texttureJumpRIGHT[],
		sf::Texture coinText[], sf::Texture waterText[]);

	void update(int direc);
	void coinUpdate();
	void waterUpdate();
	void idleUpdate(int i);
	void runUpdate(int i);
	void jumpUpdate(int i);

};

