#include "player.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

player::player()
{
	coinPoint = 0;
}

void player::playerJump(b2Body *playerBody)
{
	float karakterYon = playerBody->GetLinearVelocity().x;
	karakterYon = karakterYon - (karakterYon / 3);
	playerBody->SetLinearVelocity(b2Vec2(karakterYon, -9));

	if (karakterYon > 0) {
		direc = pJumpRight;
	}
	else if (karakterYon < 0) {
		direc = pJumpLeft;
	}
	
	if (lastGround->GetUserData() == (void*)1) {
		if (lastGround->GetType() == b2_kinematicBody) {
			lastGround->SetLinearVelocity(b2Vec2(0, +6));
		}
	}
}

void player::playerRightOnAir(b2Body * playerBody)
{
	b2Vec2 vel = playerBody->GetLinearVelocity();
	float velChange = 3 - vel.x;
	float impulse = playerBody->GetMass() * velChange;
	playerBody->ApplyLinearImpulse(b2Vec2(impulse, 0), playerBody->GetWorldCenter(), true);
	direc = pJumpRight;
}

void player::playerRight(b2Body * playerBody)
{
	b2Vec2 vel = playerBody->GetLinearVelocity();
	float velChange = 5 - vel.x;
	float impulse = playerBody->GetMass() * velChange;
	playerBody->ApplyLinearImpulse(b2Vec2(impulse, 0), playerBody->GetWorldCenter(), true);
	direc = pRunRight;
}

void player::playerLeftOnAir(b2Body * playerBody)
{
	b2Vec2 vel = playerBody->GetLinearVelocity();
	float velChange = -3 - vel.x;
	float impulse = playerBody->GetMass() * velChange;
	playerBody->ApplyLinearImpulse(b2Vec2(impulse, 0), playerBody->GetWorldCenter(), true);
	direc = pJumpLeft;
}

void player::playerLeft(b2Body * playerBody)
{
	b2Vec2 vel = playerBody->GetLinearVelocity();
	float velChange = -5 - vel.x;
	float impulse = playerBody->GetMass() * velChange;
	playerBody->ApplyLinearImpulse(b2Vec2(impulse, 0), playerBody->GetWorldCenter(), true);
	direc = pRunLeft;
}

void player::playerRightEnd(b2Body * playerBody)
{
	b2Vec2 vel = playerBody->GetLinearVelocity();
	float velChange = 0 - vel.x;
	float impulse = playerBody->GetMass() * velChange;
	playerBody->ApplyLinearImpulse(b2Vec2(impulse, 0), playerBody->GetWorldCenter(), true);
	direc = pRight;
}

void player::playerLeftEnd(b2Body * playerBody)
{
	b2Vec2 vel = playerBody->GetLinearVelocity();
	float velChange = 0 - vel.x;
	float impulse = playerBody->GetMass() * velChange;
	playerBody->ApplyLinearImpulse(b2Vec2(impulse, 0), playerBody->GetWorldCenter(), true);
	direc = pLeft;
}

b2Body * player::createPlayer(b2World *world, float X, float Y)
{
	b2BodyDef BodyDefK;
	BodyDefK.position = b2Vec2(X / 30.f, Y / 30.f);
	BodyDefK.type = b2_dynamicBody;
	b2Body *Body = world->CreateBody(&BodyDefK);

	b2PolygonShape ShapeK;
	ShapeK.SetAsBox((50.f / 2) / 30.f, (50.f / 2) / 30.f);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &ShapeK;
	Body->CreateFixture(&FixtureDef);
	return Body;
}

bool player::isPlayerOnGround(b2Body * playerBody, b2Body * groundBody[] , int groundBodyCon)
{
	for (int i = 0; i < groundBodyCon; i++) {
		float playerX = playerBody->GetPosition().x;
		float playerY = playerBody->GetPosition().y;
		float groundLeft;
		float groundRight;

		if (groundBody[i]->GetUserData() == (void*)4) {
			groundLeft = groundBody[i]->GetPosition().x - (100.f / 30.f);
			groundRight = groundBody[i]->GetPosition().x + (100.f / 30.f);
		}
		else if (groundBody[i]->GetUserData() == (void*)1) {
			groundLeft = groundBody[i]->GetPosition().x - (25.f / 30.f);
			groundRight = groundBody[i]->GetPosition().x + (25.f / 30.f);
		}

		float groundY = groundBody[i]->GetPosition().y;
		float playerGroundDif = groundY - playerY;

		if (playerX < groundRight && playerX > groundLeft && playerGroundDif > 1.5 && playerGroundDif < 1.7) {
			lastGround = groundBody[i];
			return true;
		}
	}
	return false;
}

