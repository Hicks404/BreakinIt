#include "Brick.h"
#include "Ball.h"
#include "Game.h"
#include "Score.h"
#include <raymath.h>
#include <iostream>

Brick::Brick(Vector2 location, Vector2 size, Game* game)
	: Actor{ location, size, ColorFromHSV(GetRandomValue(0, 360), 1.f, 1.f), game }, isBroken{ false }, breakframe{ 1500 }, spawning{ 0 }, savedsize{ size }
{
	
}

void Brick::apppear()
{
	spawning += 1;
}

void Brick::breaking()
{
	breakframe -= 1;
	//std::cout << breakframe << "\n";
	size.x -= 0.00069f*savedsize.x;
	size.y += 0.00054f*savedsize.y;
}

void Brick::Tick(float dt)
{
	if (breakframe <= 0)
	{
		return;
	}

	if (isBroken)
	{
		breaking();
		return;
	}

	Ball* ball = m_game->GetBall();
	Rectangle brickRect = { location.x - size.x * 0.5f, location.y - size.y * 0.5f, size.x, size.y };
	float ballRadius = Vector2Length(ball->size);

	if (CheckCollisionCircleRec(ball->location, ballRadius, brickRect))
	{
		//ball collide
		isBroken = true;

		ball->velocity.y *= -1;
		ball->moveSpeed *= 1.02;
		m_game->AddScore(1);
	}
}

void Brick::Render()
{
	if (breakframe <= 0)
	{
		return;
	}

	if (spawning < 1000)
	{
		DrawRectanglePro({ location.x, location.y, size.x * spawning / 1000, size.y * spawning / 1000 }, { size.x * 0.5f, size.y * 0.5f }, 0.f, color);
		apppear();
	}
	else
	{
		DrawRectanglePro({ location.x, location.y, size.x, size.y }, { size.x * 0.5f, size.y * 0.5f }, 0.f, color);
	}
}
