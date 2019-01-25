#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "player.h"
#include "animation.h"
class level
{
private: 

	b2World *worldP;
	b2Vec2 gravity;
	sf::RenderWindow *windowP;
	sf::View *cameraP;

	player *playerP;
	b2Body *playerBody;

	animation *animationP;

	sf::Music music;
	///////////////////////
	sf::SoundBuffer coinBuffer;
	sf::Sound coinEffect;
	sf::SoundBuffer jumpBuffer;
	sf::Sound jumpEffect;
	sf::SoundBuffer gameOverBuffer;
	sf::Sound gameOverEffect;
	sf::SoundBuffer winBuffer;
	sf::Sound winEffect;
	///////////////////////
	sf::Font font;
	sf::Text coinPoint;
	sf::Text gameOverString;
	///////////////////////

	/*TEXTURE AND SPRITE */
	sf::Texture gameWinText;
	sf::Sprite gameWinSprite;
	///////////////////////
	sf::Texture spikeUpText;
	sf::Sprite spikeUpSprite[11];
	const int spikeSpriteCon = 11;
	///////////////////////
	sf::Texture chestText;
	sf::Sprite chestSprite;
	///////////////////////
	b2Body *groundBody[15];
	sf::Texture ground1Text;
	sf::Sprite ground1Sprite;
	sf::Texture ground4Text;
	sf::Sprite ground4Sprite;
	const int groundBodyCon = 15;
	/////////////////////////
	sf::Texture backgroundText;
	sf::Sprite backgroundSprite;
	/////////////////////////
	sf::Texture coinText[16];
	sf::Sprite coinSprite[5];
	const int coinSpriteCon = 5;
	bool coinList[5];
	/////////////////////////
	sf::Texture coinLogoText;
	sf::Sprite coinLogo;
	/////////////////////////
	sf::Texture waterText[17];
	sf::Sprite waterSprite[13];
	const int waterSpriteCon = 13;
	/////////////////////////
	sf::Texture textureIdleRIGHT[11];
	sf::Texture textureIdleLEFT[11];
	sf::Texture textureJumpRIGHT[2];
	sf::Texture textureJumpLEFT[2];
	sf::Texture textureRunRIGHT[13];
	sf::Texture textureRunLEFT[13];
	/////////////////////////
	sf::Sprite playerSprite;
	/////////////////////////
	sf::Texture restartText;
	sf::Sprite restartSprite;
	/////////////////////////

	float mouseCameraX;
	bool levelOneCorrect;

public:
	level();
	level(int screenX, int screenY);
	void createLevelOne();
	bool levelOneUpdate();
	bool levelOneLose();
	

private:
	void setupTextSprite();
	void setupBody();
	void setWaterSprite();
	void setCoinSprite();
	void setSpikeUpSprite();
	void levelOneDraw();
	void animationControl();
	void animationSetup();
	bool isPlayerAlive();
	void coinControl();
	void coinLogoMovement();
	void controlKinematicGround();
	bool isGameEnd();
	void levelOneWin();
	void cameraControl();
	void cameraMovement();

	b2Body* createStaticGround(float X, float Y);

	b2Body* createKinematicFourGround(float X, float Y);

	b2Body* createJumpDropSingleGround(float X, float Y);
	
};

