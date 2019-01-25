#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
class player
{
public:
	enum  direction { pLeft = 0, pRight = 1, pJumpLeft = 2, pJumpRight = 3, pRunLeft = 4, pRunRight = 5 };
	direction direc = pRight;
	int coinPoint;
private:
	b2Body *playerBody;
	b2Body *lastGround;
public:
	player();
	b2Body *createPlayer(b2World *world, float X, float Y);
	bool isPlayerOnGround(b2Body *playerBody, b2Body *groundBody[], int groundBodyCon);
	void playerJump(b2Body *playerBody);
	void playerRightOnAir(b2Body *playerBody);
	void playerRight(b2Body *playerBody);
	void playerLeftOnAir(b2Body *playerBody);
	void playerLeft(b2Body *playerBody);
	void playerRightEnd(b2Body *playerBody);
	void playerLeftEnd(b2Body *playerBody);
};

