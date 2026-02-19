#pragma once
#include "Actor.h"
class Brick : public Actor
{
public:
	bool isBroken;
	int breakframe;
	int spawning;
	Vector2 savedsize;

public:
	Brick(Vector2 location, Vector2 size, Game* game);

public:
	void apppear();
	void breaking();

public:
	void Tick(float dt) override;
	void Render() override;
};

