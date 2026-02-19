#include "Level.h"
#include "Game.h"

#include <iostream>
#include <string>
using std::string;

#define score m_game->GetScore()
#define w m_game->GetWidth()
#define h m_game->GetHeight()
#define level m_game->GetLevel()

Level::Level(Game* game)
	: Actor{ { game->GetWidth() * 0.5f, game->GetHeight() * 0.5f }, {10.f, 10.f}, WHITE, game }, brickcount{ 0 }, totalcount{ 0 }
{
	
}

void Level::LoadLevel(int Level)
{
	float padding = 5.f;
	
	const int Layout[][2] = {
		//{7,6},
		{1,1},
		{3,2},
		{4,3},
		{5,6},
		{7,6},
		{8,8},
		{10,8}
	};

	int brickXCount = Layout[Level - 1][0];
	int brickYCount = Layout[Level - 1][1];
	brickcount = brickXCount * brickYCount;
	totalcount += brickcount;

	Vector2 brickSize = { (w * .97f) / brickXCount - padding, (h * .4f) / brickYCount - padding };
	//std::cout << brickXCount << " " << brickSize.x << "\n";
	for (int x = 0; x < brickXCount; ++x)
	{
		for (int y = 0; y < brickYCount; ++y)
		{
			Vector2 brickPos =
			{
				x * (brickSize.x + padding) + brickSize.x / 2 + w * .015f,
				y * (brickSize.y + padding) + y * brickSize.y / 15 + h * .05f
			};

			//std::cout << x << " " << y << "\n";
			if (brickPos.x && brickPos.y)
			{
				//std::cout << 3;
				m_game->PlaceBrick(brickPos, brickSize);
			}
		}
	}
}

void Level::BeginPlay()
{
	LoadLevel(level);
}

void Level::Tick(float dt)
{
	if (score == totalcount)
	{
		m_game->AddLevel(1);
		LoadLevel(level);
		//std::cout << totalcount;
	}
}

void Level::Render()
{
	
}
