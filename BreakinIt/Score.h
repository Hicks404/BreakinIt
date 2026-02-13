#pragma once
#include "Actor.h"
class Score : public Actor
{
public:
	Score(Game* game);

public:
	void BeginPlay() override;

	void Tick(float dt) override;
	void Render() override;
};

