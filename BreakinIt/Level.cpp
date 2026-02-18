#include "Level.h"
#include "Game.h"
#include "Brick.h"

#include <iostream>
#include <string>
using std::string;

Level::Level(Game* game)
	: Actor{ { game->GetWidth() * 0.5f, game->GetHeight() * 0.5f }, {10.f, 10.f}, WHITE, game }
{
	
}

void Level::LoadLevel(int Level)
{
	float padding = 5.f;

	int Layout[][2] = {
		{7,6},
		{7,6}
	};

	int brickXCount = Layout[Level - 1][0];
	int brickYCount = Layout[Level - 1][1];

	int w = m_game->GetWidth();
	int h = m_game->GetHeight();

	Vector2 brickSize = { (w * .97f) / brickXCount - padding, (h * .4f) / brickYCount - padding };
	for (int x = 0; x < brickXCount; ++x)
	{
		for (int y = 0; y < brickYCount; ++y)
		{
			Vector2 brickPos =
			{
				x * (brickSize.x + padding) + brickSize.x / 2 + w * .015f,
				y * (brickSize.y + padding) + y * brickSize.y / 15 + h * .05f
			};

			m_actors.emplace_back(new Brick{ brickPos, brickSize, this });
		}
	}
}

void Level::BeginPlay()
{}

void Level::Tick(float dt)
{}

void Level::Render()
{}
