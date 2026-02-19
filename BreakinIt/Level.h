#pragma once
#include "Actor.h"

class Level : public Actor
{
public:
	Level(Game* game);

	int brickcount;
	int totalcount;

public:
	void LoadLevel(int Level);

public:
	void BeginPlay() override;

	void Tick(float dt) override;
	void Render() override;
};