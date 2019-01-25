#include "level.h"
#include "player.h"
#include "animation.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <string>
#include <Windows.h>

level::level()
{
	windowP = new sf::RenderWindow(sf::VideoMode(800, 600), "Platform Game");
	windowP->setFramerateLimit(60);

	cameraP = new sf::View(sf::Vector2f(0.f, 0.f), sf::Vector2f(float(800), float(600)));

	gravity = b2Vec2(0.f, 9.8f);
	worldP = new b2World(gravity);

	playerP = new player();
	animationP = new animation();

	levelOneCorrect = true;
}

level::level(int screenX, int screenY) {
	windowP = new sf::RenderWindow(sf::VideoMode(screenX, screenY), "Platform Game");
	windowP->setFramerateLimit(60);

	cameraP = new sf::View(sf::Vector2f(0.f, 0.f), sf::Vector2f(float(screenX), float(screenY)));

	gravity = b2Vec2(0.f, 9.8f);
	worldP = new b2World(gravity);
	
	playerP = new player();
	animationP = new animation();

	levelOneCorrect = true;
}

void level::createLevelOne()
{
	setupTextSprite();
	setupBody();
	animationSetup();
}

void level::setupTextSprite()
{
	/*FONT*/
	font.loadFromFile("arialn.TTF");

	/*MUSIC*/
	music.openFromFile("soundEffect/backgroundEffect.ogg");
	music.setLoop(true);
	music.play();
	/*RESTART*/
	restartText.loadFromFile("texturePack/restart.png");
	restartSprite.setTexture(restartText);
	restartSprite.setPosition(sf::Vector2f(400, 350));
	restartSprite.setOrigin(sf::Vector2f(100.f, 50.f));

	/*GAMEWIN*/
	gameWinText.loadFromFile("texturePack/win.png");
	gameWinSprite.setTexture(gameWinText);
	gameWinSprite.setOrigin(sf::Vector2f(100.f, 50.f));
	gameWinSprite.setPosition(sf::Vector2f(400, 250));

	/*GAMEOVERTEXT*/
	gameOverString.setFont(font);
	gameOverString.setCharacterSize(30);
	gameOverString.setFillColor(sf::Color::White);
	gameOverString.setPosition(sf::Vector2f(325, 250));
	gameOverString.setString("GAME OVER");

	/*CHEST*/
	chestText.loadFromFile("texturePack/chest.png");
	chestSprite.setTexture(chestText);
	chestSprite.setPosition(sf::Vector2f(1975, 525));
	chestSprite.setOrigin(sf::Vector2f(25.f, 25.f));

	/*SOUNDEFFECT*/
	coinBuffer.loadFromFile("soundEffect/coinEffect.ogg");
	coinEffect.setBuffer(coinBuffer);
	jumpBuffer.loadFromFile("soundEffect/jumpEffect.ogg");
	jumpEffect.setBuffer(jumpBuffer);
	gameOverBuffer.loadFromFile("soundEffect/gameOverEffect.ogg");
	gameOverEffect.setBuffer(gameOverBuffer);
	winBuffer.loadFromFile("soundEffect/winEffect.ogg");
	winEffect.setBuffer(winBuffer);

	/*COINTEXT*/
	coinPoint.setFont(font);
	coinPoint.setCharacterSize(30);
	coinPoint.setFillColor(sf::Color::Black);
	coinPoint.setPosition(sf::Vector2f(125, 55));
	coinPoint.setString('0');

	/*GROUND*/
	ground4Text.loadFromFile("texturePack/groundText/ground4.png");
	ground4Sprite.setTexture(ground4Text);
	ground4Sprite.setOrigin(100.f, 25.f);
	ground1Text.loadFromFile("texturePack/groundText/ground1.png");
	ground1Sprite.setTexture(ground1Text);
	ground1Sprite.setOrigin(25.f, 25.f);

	/*BACKGROUND*/
	backgroundText.loadFromFile("texturePack/background.png");
	backgroundSprite.setTexture(backgroundText);

	/*SPIKEUP*/
	spikeUpText.loadFromFile("texturePack/enemyText/spikeUp.png");
	setSpikeUpSprite();

	/*COIN*/
	coinText[0].loadFromFile("texturePack/coinText/1.png");
	coinText[1].loadFromFile("texturePack/coinText/2.png");
	coinText[2].loadFromFile("texturePack/coinText/3.png");
	coinText[3].loadFromFile("texturePack/coinText/4.png");
	coinText[4].loadFromFile("texturePack/coinText/5.png");
	coinText[5].loadFromFile("texturePack/coinText/6.png");
	coinText[6].loadFromFile("texturePack/coinText/7.png");
	coinText[7].loadFromFile("texturePack/coinText/8.png");
	coinText[8].loadFromFile("texturePack/coinText/9.png");
	coinText[9].loadFromFile("texturePack/coinText/10.png");
	coinText[10].loadFromFile("texturePack/coinText/11.png");
	coinText[11].loadFromFile("texturePack/coinText/12.png");
	coinText[12].loadFromFile("texturePack/coinText/13.png");
	coinText[13].loadFromFile("texturePack/coinText/14.png");
	coinText[14].loadFromFile("texturePack/coinText/15.png");
	coinText[15].loadFromFile("texturePack/coinText/16.png");
	coinLogoText.loadFromFile("texturePack/coin.png");
	setCoinSprite();

	/*WATER*/
	waterText[0].loadFromFile("texturePack/waterText/1.png");
	waterText[1].loadFromFile("texturePack/waterText/2.png");
	waterText[2].loadFromFile("texturePack/waterText/3.png");
	waterText[3].loadFromFile("texturePack/waterText/4.png");
	waterText[4].loadFromFile("texturePack/waterText/5.png");
	waterText[5].loadFromFile("texturePack/waterText/6.png");
	waterText[6].loadFromFile("texturePack/waterText/7.png");
	waterText[7].loadFromFile("texturePack/waterText/8.png");
	waterText[8].loadFromFile("texturePack/waterText/9.png");
	waterText[9].loadFromFile("texturePack/waterText/10.png");
	waterText[10].loadFromFile("texturePack/waterText/11.png");
	waterText[11].loadFromFile("texturePack/waterText/12.png");
	waterText[12].loadFromFile("texturePack/waterText/13.png");
	waterText[13].loadFromFile("texturePack/waterText/14.png");
	waterText[14].loadFromFile("texturePack/waterText/15.png");
	waterText[15].loadFromFile("texturePack/waterText/16.png");
	waterText[16].loadFromFile("texturePack/waterText/17.png");
	setWaterSprite();

	/*IDLERIGHT*/
	textureIdleRIGHT[0].loadFromFile("texturePack/idleRightText/image_part_001.png");
	textureIdleRIGHT[1].loadFromFile("texturePack/idleRightText/image_part_002.png");
	textureIdleRIGHT[2].loadFromFile("texturePack/idleRightText/image_part_003.png");
	textureIdleRIGHT[3].loadFromFile("texturePack/idleRightText/image_part_004.png");
	textureIdleRIGHT[4].loadFromFile("texturePack/idleRightText/image_part_005.png");
	textureIdleRIGHT[5].loadFromFile("texturePack/idleRightText/image_part_006.png");
	textureIdleRIGHT[6].loadFromFile("texturePack/idleRightText/image_part_007.png");
	textureIdleRIGHT[7].loadFromFile("texturePack/idleRightText/image_part_008.png");
	textureIdleRIGHT[8].loadFromFile("texturePack/idleRightText/image_part_009.png");
	textureIdleRIGHT[9].loadFromFile("texturePack/idleRightText/image_part_010.png");
	textureIdleRIGHT[10].loadFromFile("texturePack/idleRightText/image_part_011.png");

	/*IDLELEFT*/
	textureIdleLEFT[0].loadFromFile("texturePack/idleLeftText/image_part_001.png");
	textureIdleLEFT[1].loadFromFile("texturePack/idleLeftText/image_part_002.png");
	textureIdleLEFT[2].loadFromFile("texturePack/idleLeftText/image_part_003.png");
	textureIdleLEFT[3].loadFromFile("texturePack/idleLeftText/image_part_004.png");
	textureIdleLEFT[4].loadFromFile("texturePack/idleLeftText/image_part_005.png");
	textureIdleLEFT[5].loadFromFile("texturePack/idleLeftText/image_part_006.png");
	textureIdleLEFT[6].loadFromFile("texturePack/idleLeftText/image_part_007.png");
	textureIdleLEFT[7].loadFromFile("texturePack/idleLeftText/image_part_008.png");
	textureIdleLEFT[8].loadFromFile("texturePack/idleLeftText/image_part_009.png");
	textureIdleLEFT[9].loadFromFile("texturePack/idleLeftText/image_part_010.png");
	textureIdleLEFT[10].loadFromFile("texturePack/idleLeftText/image_part_011.png");

	/*JUMPRIGHT*/
	textureJumpRIGHT[0].loadFromFile("texturePack/jumpRightText/01.png");
	textureJumpRIGHT[1].loadFromFile("texturePack/jumpRightText/02.png");

	/*JUMPLEFT*/
	textureJumpLEFT[0].loadFromFile("texturePack/jumpLeftText/01.png");
	textureJumpLEFT[1].loadFromFile("texturePack/jumpLeftText/02.png");

	/*RUNRIGHT*/
	textureRunRIGHT[0].loadFromFile("texturePack/runRightText/01.png");
	textureRunRIGHT[1].loadFromFile("texturePack/runRightText/02.png");
	textureRunRIGHT[2].loadFromFile("texturePack/runRightText/03.png");
	textureRunRIGHT[3].loadFromFile("texturePack/runRightText/04.png");
	textureRunRIGHT[4].loadFromFile("texturePack/runRightText/05.png");
	textureRunRIGHT[5].loadFromFile("texturePack/runRightText/06.png");
	textureRunRIGHT[6].loadFromFile("texturePack/runRightText/07.png");
	textureRunRIGHT[7].loadFromFile("texturePack/runRightText/08.png");
	textureRunRIGHT[8].loadFromFile("texturePack/runRightText/09.png");
	textureRunRIGHT[9].loadFromFile("texturePack/runRightText/10.png");
	textureRunRIGHT[10].loadFromFile("texturePack/runRightText/11.png");
	textureRunRIGHT[11].loadFromFile("texturePack/runRightText/12.png");
	textureRunRIGHT[12].loadFromFile("texturePack/runRightText/13.png");

	/*RUNLEFT*/
	textureRunLEFT[0].loadFromFile("texturePack/runLeftText/01.png");
	textureRunLEFT[1].loadFromFile("texturePack/runLeftText/02.png");
	textureRunLEFT[2].loadFromFile("texturePack/runLeftText/03.png");
	textureRunLEFT[3].loadFromFile("texturePack/runLeftText/04.png");
	textureRunLEFT[4].loadFromFile("texturePack/runLeftText/05.png");
	textureRunLEFT[5].loadFromFile("texturePack/runLeftText/06.png");
	textureRunLEFT[6].loadFromFile("texturePack/runLeftText/07.png");
	textureRunLEFT[7].loadFromFile("texturePack/runLeftText/08.png");
	textureRunLEFT[8].loadFromFile("texturePack/runLeftText/09.png");
	textureRunLEFT[9].loadFromFile("texturePack/runLeftText/10.png");
	textureRunLEFT[10].loadFromFile("texturePack/runLeftText/11.png");
	textureRunLEFT[11].loadFromFile("texturePack/runLeftText/12.png");
	textureRunLEFT[12].loadFromFile("texturePack/runLeftText/13.png");

	/*PLAYER*/
	playerSprite.setTexture(textureIdleRIGHT[0]);
	playerSprite.setOrigin(25.f, 25.f);
}

void level::setupBody()
{
	playerBody = playerP->createPlayer(worldP, 30, 500);
	groundBody[0] = createStaticGround(100, 575);
	groundBody[1] = createStaticGround(400, 575);
	groundBody[2] = createStaticGround(700, 575);
	groundBody[3] = createStaticGround(1000, 475);
	groundBody[4] = createStaticGround(1000, 275);
	groundBody[5] = createKinematicFourGround(700, 375);
	groundBody[6] = createJumpDropSingleGround(450, 300);
	groundBody[7] = createJumpDropSingleGround(250, 300);
	groundBody[8] = createJumpDropSingleGround(50, 300);
	groundBody[9] = createJumpDropSingleGround(1250, 275);
	groundBody[10] = createJumpDropSingleGround(1350, 275);
	groundBody[11] = createJumpDropSingleGround(1450, 275);
	groundBody[12] = createJumpDropSingleGround(1550, 275);
	groundBody[13] = createJumpDropSingleGround(1650, 275);
	groundBody[14] = createStaticGround(1950, 575);
}

void level::setWaterSprite()
{
	waterSprite[0].setPosition(sf::Vector2f(200.f, 550.f));
	waterSprite[1].setPosition(sf::Vector2f(500.f, 550.f));
	waterSprite[2].setPosition(sf::Vector2f(800.f, 550.f));
	waterSprite[3].setPosition(sf::Vector2f(900.f, 550.f));
	waterSprite[4].setPosition(sf::Vector2f(1000.f, 550.f));
	waterSprite[5].setPosition(sf::Vector2f(1100.f, 550.f));
	waterSprite[6].setPosition(sf::Vector2f(1200.f, 550.f));
	waterSprite[7].setPosition(sf::Vector2f(1300.f, 550.f));
	waterSprite[8].setPosition(sf::Vector2f(1400.f, 550.f));
	waterSprite[9].setPosition(sf::Vector2f(1500.f, 550.f));
	waterSprite[10].setPosition(sf::Vector2f(1600.f, 550.f));
	waterSprite[11].setPosition(sf::Vector2f(1700.f, 550.f));
	waterSprite[12].setPosition(sf::Vector2f(1800.f, 550.f));

}

void level::setCoinSprite()
{
	coinLogo.setTexture(coinLogoText);
	coinLogo.setPosition(sf::Vector2f(50.f, 50.f));

	for (int i = 0; i < coinSpriteCon; i++) {
		coinSprite[i].setOrigin(25.f, 25.f);
		coinList[i] = true;
	}

	coinSprite[0].setPosition(sf::Vector2f(400.f, 415.f));
	coinSprite[1].setPosition(sf::Vector2f(150.f, 150.f));
	coinSprite[2].setPosition(sf::Vector2f(350.f, 150.f));
	coinSprite[3].setPosition(sf::Vector2f(1000.f, 125.f));
	coinSprite[4].setPosition(sf::Vector2f(1450.f, 200.f));

	
}

void level::setSpikeUpSprite()
{
	for (int i = 0; i < spikeSpriteCon; i++) {
		spikeUpSprite[i].setTexture(spikeUpText);
		spikeUpSprite[i].setOrigin(sf::Vector2f(12.5f, 12.5f));
	}

	spikeUpSprite[0].setPosition(sf::Vector2f(375, 545));
	spikeUpSprite[1].setPosition(sf::Vector2f(400, 545));
	spikeUpSprite[2].setPosition(sf::Vector2f(425, 545));
	spikeUpSprite[3].setPosition(sf::Vector2f(700, 545));
	spikeUpSprite[4].setPosition(sf::Vector2f(675, 545));
	spikeUpSprite[5].setPosition(sf::Vector2f(725, 545));
	spikeUpSprite[6].setPosition(sf::Vector2f(975, 245));
	spikeUpSprite[7].setPosition(sf::Vector2f(1000, 245));
	spikeUpSprite[8].setPosition(sf::Vector2f(1025, 245));
	spikeUpSprite[9].setPosition(sf::Vector2f(1350, 250));
	spikeUpSprite[10].setPosition(sf::Vector2f(1550, 250));


}

void level::animationSetup()
{
	animationP->setupSprite(&playerSprite, coinSprite, waterSprite);
	animationP->setupText(textureIdleLEFT, textureIdleRIGHT,
		textureRunLEFT, textureRunRIGHT, textureJumpLEFT, textureJumpRIGHT, coinText, waterText);
}

bool level::levelOneUpdate()
{
	while (windowP->isOpen() && levelOneCorrect == true) {
		worldP->Step(1 / 60.f, 8, 3);

		sf::Event olay;

		while (windowP->pollEvent(olay)) {
			if (olay.type == sf::Event::Closed)
				windowP->close();
			////////////////////////////////////////////
			if (olay.type == sf::Event::KeyPressed &&
				olay.key.code == sf::Keyboard::Space && playerP->isPlayerOnGround(playerBody, groundBody, groundBodyCon)) {
				playerP->playerJump(playerBody);
				animationP->isPlayerOnAir = false;
				jumpEffect.play();
			}
			///////////////////////////////////////////
			if (olay.type == sf::Event::KeyPressed && olay.key.code == sf::Keyboard::D) {
				if (!playerP->isPlayerOnGround(playerBody, groundBody, groundBodyCon))
					playerP->playerRightOnAir(playerBody);
				else {
					playerP->playerRight(playerBody);
					animationP->isPlayerOnAir = false;
				}
			}
			///////////////////////////////////////////
			if (olay.type == sf::Event::KeyPressed && olay.key.code == sf::Keyboard::A) {
				if (!playerP->isPlayerOnGround(playerBody, groundBody, groundBodyCon)) 
					playerP->playerLeftOnAir(playerBody);
				else {
					playerP->playerLeft(playerBody);
					animationP->isPlayerOnAir = false;
				}
			}
			///////////////////////////////////////////
			if (olay.type == sf::Event::KeyReleased && olay.key.code == sf::Keyboard::D) {
				if (playerP->isPlayerOnGround(playerBody, groundBody, groundBodyCon)) { 
					playerP->playerRightEnd(playerBody);
					animationP->isPlayerOnAir = false;
				}
			}
			///////////////////////////////////////////
			if (olay.type == sf::Event::KeyReleased && olay.key.code == sf::Keyboard::A) {
				if (playerP->isPlayerOnGround(playerBody, groundBody, groundBodyCon)) { 
					playerP->playerLeftEnd(playerBody);
					animationP->isPlayerOnAir = false;
				}
			}
			///////////////////////////////////////////
			if (olay.type == sf::Event::KeyPressed && olay.key.code == sf::Keyboard::C) {
				playerBody->SetLinearVelocity(b2Vec2(10, -10));
			}
		}
		

		windowP->clear(sf::Color::White);

		cameraControl();

		playerSprite.setPosition(playerBody->GetPosition().x * 30.f, playerBody->GetPosition().y * 30.f);

		animationControl();

		controlKinematicGround();

		coinControl();

		levelOneDraw();

		bool alive = isPlayerAlive();

		if (alive == false)
			levelOneCorrect = false;

		bool gameEnd = isGameEnd();

		if (gameEnd == true) {
			break;
		}

	}

	if (levelOneCorrect == true) {
		music.stop();
		winEffect.play();
		levelOneWin();
		return true;
	}
	else {
		music.stop();
		gameOverEffect.play();
		return false;
	}
}

void level::coinLogoMovement()
{
	int playerX = playerSprite.getPosition().x - 350;
	coinLogo.setPosition(sf::Vector2f(playerX, 50.f));
	coinPoint.setPosition(sf::Vector2f(playerX + 75, 55.f));
}

void level::animationControl()
{
	if (!playerP->isPlayerOnGround(playerBody, groundBody, groundBodyCon)) {
		animationP->update(playerP->direc);
	}
	else if (playerP->isPlayerOnGround(playerBody, groundBody, groundBodyCon)) {
		animationP->update(playerP->direc);
	}
	else if (playerP->isPlayerOnGround(playerBody, groundBody, groundBodyCon) && (playerP->direc == 4 || playerP->direc == 5)) {
		animationP->update(playerP->direc);
	}
}

void level::coinControl()
{
	for (int i = 0; i < coinSpriteCon; i++) {
		float playerX = playerSprite.getPosition().x;
		float playerY = playerSprite.getPosition().y;
		float coinX = coinSprite[i].getPosition().x;
		float coinY = coinSprite[i].getPosition().y;

		float difX = coinX - playerX;
		float difY = coinY - playerY;

		if (difX <= 25 && difX >= -25 && difY <= 25 && difY >= -25 && coinList[i] == true) {
			playerP->coinPoint++;
			coinList[i] = false;
			coinPoint.setString(std::to_string(playerP->coinPoint));
			coinEffect.play();
		}
	}
}

void level::cameraControl()
{
	if (playerSprite.getPosition().x > 400 && playerSprite.getPosition().x < 1650) {
		cameraP->setCenter(playerSprite.getPosition().x, 300);
		windowP->setView(*cameraP);
		coinLogoMovement();
		cameraMovement();
	}
}

void level::controlKinematicGround()
{
	if ((groundBody[5]->GetPosition().y * 30.f) <= 200)
		groundBody[5]->SetLinearVelocity(b2Vec2(0, +2));
	else if ((groundBody[5]->GetPosition().y * 30.f) >= 375)
		groundBody[5]->SetLinearVelocity(b2Vec2(0, -2));
}

void level::cameraMovement()
{
	int playerX = playerSprite.getPosition().x - 350;
	mouseCameraX = playerSprite.getPosition().x - 400;
	gameOverString.setPosition(sf::Vector2f(playerX + 285, 250)); // 335, 250
	restartSprite.setPosition(sf::Vector2f(playerX + 365, 350));
	backgroundSprite.setPosition(sf::Vector2f((playerBody->GetPosition().x * 30.f) - 405, 0));
	gameWinSprite.setPosition(sf::Vector2f(playerX + 365, 300));
}

bool level::isPlayerAlive()
{
	if (playerSprite.getPosition().y > 600) {
		levelOneCorrect = false;
		return false;
	}

	for (int i = 0; i < spikeSpriteCon; i++) {
		float playerX = playerSprite.getPosition().x;
		float playerY = playerSprite.getPosition().y;
		float spikeX = spikeUpSprite[i].getPosition().x;
		float spikeY = spikeUpSprite[i].getPosition().y;

		float difX = spikeX - playerX;
		float difY = spikeY - playerY;

		if (difX <= 25 && difX >= -25 && difY <= 30 && difY >= -30) {
			levelOneCorrect = false;
			return false;
		}
	}

	return true;
}

void level::levelOneDraw()
{

	windowP->draw(backgroundSprite);
	windowP->draw(coinLogo);
	windowP->draw(coinPoint);
	windowP->draw(chestSprite);

	for (int i = 0; i < coinSpriteCon; i++) {
		if (coinList[i] == true)
			windowP->draw(coinSprite[i]);
	}

	for (int i = 0; i < spikeSpriteCon ; i++) {
		windowP->draw(spikeUpSprite[i]);
	}

	windowP->draw(playerSprite);

	for (int i = 0; i < waterSpriteCon ; i++) {
		windowP->draw(waterSprite[i]);
	}

	for (int i = 0; i < groundBodyCon ; i++) {
		if (groundBody[i]->GetUserData() == (void*)1) {
			ground1Sprite.setPosition(groundBody[i]->GetPosition().x * 30.f, groundBody[i]->GetPosition().y * 30.f);
			windowP->draw(ground1Sprite);
		}
		else if (groundBody[i]->GetUserData() == (void*)4) {
			ground4Sprite.setPosition(groundBody[i]->GetPosition().x * 30.f, groundBody[i]->GetPosition().y * 30.f);
			windowP->draw(ground4Sprite);
		}
		else if (groundBody[i]->GetUserData() == (void*)11) {
			ground1Sprite.setPosition(groundBody[i]->GetPosition().x * 30.f, groundBody[i]->GetPosition().y * 30.f);
			windowP->draw(ground1Sprite);
		}
	}
	

	windowP->display();

}

bool level::isGameEnd()
{
	float playerX = playerSprite.getPosition().x;
	float playerY = playerSprite.getPosition().y;
	float chestX = chestSprite.getPosition().x;
	float chestY = chestSprite.getPosition().y;

	float difX = chestX - playerX;
	float difY = chestY - playerY;

	if (difX <= 25 && difX >= -25 && difY <= 25 && difY >= -25) {
		levelOneCorrect = true;
		return true;
	}

	return false;
}

bool level::levelOneLose()
{
	while (windowP->isOpen()) {
		windowP->clear(sf::Color::Black);
		windowP->draw(gameOverString);
		windowP->draw(restartSprite);
		windowP->display();

		sf::Event olay;

		while (windowP->pollEvent(olay)) {
			if (olay.type == sf::Event::Closed)
				return false;
			if (olay.type == sf::Event::MouseButtonPressed && olay.mouseButton.button == sf::Mouse::Left) {
				float mouseX = sf::Mouse::getPosition(*windowP).x + mouseCameraX;
				float mouseY = sf::Mouse::getPosition(*windowP).y;
				float restartX = restartSprite.getPosition().x;
				float restartY = restartSprite.getPosition().y;

				float difX = restartX - mouseX;
				float difY = restartY - mouseY;

				if (difX <= 100 && difX > -100 && difY <= 50 && difY > -50) {
					windowP->close();
					return true;
				}
			}
		}
	}
}

void level::levelOneWin()
{
	while (windowP->isOpen()) {
		windowP->clear(sf::Color::Black);
		windowP->draw(gameWinSprite);
		windowP->display();
		Sleep(3000);
	}
}

b2Body * level::createStaticGround(float X, float Y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X / 30.f, Y / 30.f); // 30.f = SCALE
	BodyDef.type = b2_staticBody;
	b2Body *Body = worldP->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((200.f / 2) / 30.f, (50.f / 2) / 30.f);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	Body->SetUserData((void*)4);
	return Body;
}

b2Body * level::createKinematicFourGround(float X, float Y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X / 30.f, Y / 30.f); // 30.f = SCALE
	BodyDef.type = b2_kinematicBody;
	b2Body *Body = worldP->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((200.f / 2) / 30.f, (50.f / 2) / 30.f);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	Body->SetUserData((void*)4);
	return Body;
}

b2Body * level::createJumpDropSingleGround(float X, float Y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X / 30.f, Y / 30.f); // 30.f = SCALE
	BodyDef.type = b2_kinematicBody;
	b2Body *Body = worldP->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((50.f / 2) / 30.f, (50.f / 2) / 30.f);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	Body->SetUserData((void*)1);
	return Body;
}





