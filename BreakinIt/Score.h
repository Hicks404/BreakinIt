#pragma once
#include "Actor.h"
#include <iostream>

class Score : public Actor
{
public:
	Score(Game* game);

public:
	void DisplayVar(int value, std::string txt, Color col, float x, float y, int size);

public:
	void BeginPlay() override;

	void Tick(float dt) override;
	void Render() override;
};

