#include "Score.h"
#include "Game.h"
#include <iostream>
#include <string>
using std::string;

#define score m_game->GetScore()

Score::Score(Game* game)
	: Actor{ { game->GetWidth() * 0.5f, game->GetHeight() * 0.5f }, {10.f, 10.f}, WHITE, game }
{

}

void Score::BeginPlay()
{

}

void Score::Tick(float dt)
{
	
}

void Score::Render()
{
	string scoreTxt = "Score: ";
	scoreTxt += std::to_string(score);
	const char* charST = scoreTxt.c_str();
	DrawText(charST, m_game->GetWidth() * 0.85f, m_game->GetHeight() * 0.9f, 30, LIGHTGRAY);
}
