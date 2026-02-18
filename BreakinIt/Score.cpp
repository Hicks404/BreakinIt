#include "Score.h"
#include "Game.h"
#include <iostream>
#include <string>
using std::string;

#define score m_game->GetScore()
#define death m_game->GetDeath()
#define level m_game->GetLevel()

Score::Score(Game* game)
	: Actor{ { game->GetWidth() * 0.5f, game->GetHeight() * 0.5f }, {10.f, 10.f}, WHITE, game }
{

}

void Score::DisplayVar(int value, std::string txt, Color col, float x, float y, int size)
{
	txt += std::to_string(value);
	const char* charST = txt.c_str();
	DrawText(charST, m_game->GetWidth() * x, m_game->GetHeight() * y, size, col);
}

void Score::BeginPlay()
{

}

void Score::Tick(float dt)
{
	
}

void Score::Render()
{
	DisplayVar(level, "Level: ", LIGHTGRAY, 0.82f, 0.80f, 30);
	DisplayVar(score, "Score: ", LIGHTGRAY, 0.82f, 0.85f, 30);
	DisplayVar(death, "Deaths: ", LIGHTGRAY, 0.82f, 0.9f, 30);
}
