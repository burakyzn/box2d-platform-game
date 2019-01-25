#include "animation.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

animation::animation()
{
	isPlayerOnAir = false;

	idleCont = 0;
	runCont = 0;
	coinCont = 0;
	waterCont = 0;

}

void animation::setupSprite(sf::Sprite *playerSprite, sf::Sprite coinSprite[], sf::Sprite waterSprite[])
{
	this->playerSprite = playerSprite;
	this->coinSprite = coinSprite;
	this->waterSprite = waterSprite;
}

void animation::setupText(sf::Texture textureIdleLEFT[], sf::Texture textureIdleRIGHT[],
	sf::Texture texttureRunLEFT[], sf::Texture texttureRunRIGHT[], sf::Texture texttureJumpLEFT[], sf::Texture texttureJumpRIGHT[],
	sf::Texture coinText[], sf::Texture waterText[])
{
	for (int i = 0; i < 16; i++) {
		this->coinText[i] = coinText[i];
	}

	for (int i = 0; i < 11; i++) {
		this->textureIdleLEFT[i] = textureIdleLEFT[i];
		this->textureIdleRIGHT[i] = textureIdleRIGHT[i];
		this->textureRunLEFT[i] = texttureRunLEFT[i];
		this->textureRunRIGHT[i] = texttureRunRIGHT[i];
	}

	for (int i = 0; i < 17; i++) {
		this->waterText[i] = waterText[i];
	}

	this->textureRunLEFT[11] = texttureRunLEFT[11];
	this->textureRunLEFT[12] = texttureRunLEFT[12];
	this->textureRunRIGHT[11] = texttureRunRIGHT[11];
	this->textureRunRIGHT[12] = texttureRunRIGHT[12];

	this->textureJumpLEFT[0] = texttureJumpLEFT[0];
	this->textureJumpLEFT[1] = texttureJumpLEFT[1];
	this->textureJumpRIGHT[0] = texttureJumpRIGHT[0];
	this->textureJumpRIGHT[1] = texttureJumpRIGHT[1];
}

void animation::update(int direc)
{
	if (direc == 0 || direc == 1)
		idleUpdate(direc);
	else if (direc == 2 || direc == 3)
		jumpUpdate(direc);
	else if (direc == 4 || direc == 5)
		runUpdate(direc);

	coinUpdate();
	waterUpdate();
}

void animation::coinUpdate()
{
	if (clockCoin.getElapsedTime().asSeconds() > 0.1f) {
		if (coinCont == 15)
			coinCont = 0;
		else
			coinCont++;

		for (int i = 0; i < coinSpriteCon ; i++) {
			coinSprite->setTexture(coinText[coinCont]);
			coinSprite++;
		}

		coinSprite -= coinSpriteCon ;

		clockCoin.restart();
	}
}

void animation::waterUpdate()
{
	if (clockWater.getElapsedTime().asSeconds() > 0.1f) {
		if (waterCont == 16)
			waterCont = 0;
		else
			waterCont++;

		for (int i = 0; i < waterSpriteCon; i++) {
			waterSprite->setTexture(waterText[waterCont]);
			waterSprite++;
		}

		waterSprite -= waterSpriteCon;

		clockWater.restart();
	}
}

void animation::idleUpdate(int i)
{
	if (clockYon.getElapsedTime().asSeconds() > 0.2f) {
		if (idleCont == 10)
			idleCont = 0;
		else
			idleCont++;

		if (i == 0)
			playerSprite->setTexture(this->textureIdleLEFT[idleCont]);
		else
			playerSprite->setTexture(this->textureIdleRIGHT[idleCont]);

		clockYon.restart();
	}
}

void animation::runUpdate(int i)
{
	if (clockRun.getElapsedTime().asSeconds() > 0.1f) {
		if (runCont == 12)
			runCont = 0;
		else
			runCont++;

		if (i == 4)
			playerSprite->setTexture(this->textureRunLEFT[runCont]);
		else
			playerSprite->setTexture(this->textureRunRIGHT[runCont]);

		clockRun.restart();
	}
}

void animation::jumpUpdate(int i)
{
	if (clockJump.getElapsedTime().asSeconds() > 0.3f) {
		if (i == 3 && isPlayerOnAir == false) {
			isPlayerOnAir = true;
			playerSprite->setTexture(textureJumpRIGHT[0]);
		}
		else if (i == 3 && isPlayerOnAir == true) {
			playerSprite->setTexture(textureJumpRIGHT[1]);
		}
		else if (i == 2 && isPlayerOnAir == false) {
			isPlayerOnAir = true;
			playerSprite->setTexture(textureJumpLEFT[0]);
		}
		else if (i == 2 && isPlayerOnAir == true) {
			playerSprite->setTexture(textureJumpLEFT[1]);
		}

		clockJump.restart();
	}
}

