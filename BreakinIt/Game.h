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

	Ball* GetBall();

private:
	int m_width;
	int m_height;
	string m_title;
	Color m_clrColor;

	Ball* m_ball;
	vector<Actor*> m_actors;

private:
	void BeginPlay(); //Game run function

	void Tick(float dt); //every frame

	void Render(); //Draw function

	void EndPlay(); //Cleanup actors or memory
};

