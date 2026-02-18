#pragma once

#include <vector>
#include <raylib.h>
#include <string>
using std::string;
using std::vector;

class Actor;
class Ball;

class Game
{
public:
	Game(int w, int h, string title, Color clrColor);
	~Game();

public:
	int Run();

	int GetWidth() const;
	int GetHeight() const;

	int GetScore();
	int GetDeath();
	int GetLevel();
	void AddScore(int amount);
	void AddDeath(int amount);
	void AddLevel(int amount);

	Ball* GetBall();

private:
	int m_width;
	int m_height;
	string m_title;
	Color m_clrColor;

	int m_score;
	int m_death;
	int m_level;

	Ball* m_ball;
	vector<Actor*> m_actors;

private:
	void BeginPlay(); //Game run function

	void Tick(float dt); //every frame

	void Render(); //Draw function

	void EndPlay(); //Cleanup actors or memory
};

