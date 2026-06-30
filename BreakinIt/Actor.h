#pragma once

#include <raylib.h>

class Game;

class Actor
{
public:
	Vector2 location;
	Vector2 size;
	Color color;
	int obj;

public:
	Actor(Vector2 location, Vector2 size, Color color, Game* game, int obj);
	~Actor();

public:
	virtual void BeginPlay();

	virtual void Tick(float dt);
	virtual void Render();

	virtual void EndPlay();

protected:
	Game* m_game;
};

