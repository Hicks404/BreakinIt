#include "Game.h"

#include <cstdlib>
#include "Actor.h"
#include "Paddle.h"
#include "Brick.h"
#include "Ball.h"
#include "Score.h"
#include <ctime>

Game::Game(int w, int h, string title, Color clrColor)
	: m_width{ w }, m_height{ h }, m_title{ title }, m_clrColor{ clrColor }, m_level{ 1 }
{
	int brickXCount = 7;
	int brickYCount = 6;
	float padding = 5.f;

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

	m_ball = new Ball{ this };
	m_actors.emplace_back(m_ball);

	m_actors.emplace_back(new Paddle{ this });

	m_actors.emplace_back(new Score{ this });
}

Game::~Game()
{
	for (Actor* actor : m_actors)
	{
		delete actor;
	}

	m_actors.clear();
}

int Game::Run()
{
	InitWindow(m_width, m_height, m_title.c_str());

	if (!IsWindowReady()) //If window opens succesfully
	{
		return EXIT_FAILURE; //returns failure when not
	}

	BeginPlay();

	while (!WindowShouldClose())
	{
		Tick(GetFrameTime());

		BeginDrawing();
		ClearBackground(m_clrColor);

		Render();
		EndDrawing();
	}

	EndPlay();
	CloseWindow();

	return EXIT_SUCCESS;
}

int Game::GetWidth() const
{
	return m_width;
}

int Game::GetHeight() const
{
	return m_height;
}

Ball* Game::GetBall()
{
	return m_ball;
}

int Game::GetScore()
{
	return m_score;
}

int Game::GetDeath()
{
	return m_death;
}

int Game::GetLevel()
{
	return m_level;
}

void Game::AddScore(int amount)
{
	m_score += amount;
}

void Game::AddDeath(int amount)
{
	m_death += amount;
}

void Game::AddLevel(int amount)
{
	m_level += amount;
}

void Game::BeginPlay()
{
	SetRandomSeed(time(nullptr));

	for (Actor* actor : m_actors)
	{
		actor->BeginPlay();
	}
}

void Game::Tick(float dt)
{
	for (Actor* actor : m_actors)
	{
		actor->Tick(dt);
	}
}

void Game::Render()
{
	for (Actor* actor : m_actors)
	{
		actor->Render();
	}
}

void Game::EndPlay()
{
	for (Actor* actor : m_actors)
	{
		actor->EndPlay();
	}
}
