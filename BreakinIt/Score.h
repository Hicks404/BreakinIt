#pragma once
#include "Actor.h"
class Score : public Actor
{
public:
	int score;
	int deaths;

public:
	void BeginPlay() override;

	void Tick(float dt) override;
	void Render() override;
};

