#pragma once
#include "Actor.h"

class Level : public Actor
{
public:
	Level(Game* game);

public:
	void LoadLevel(int Level);

private:
	vector<Actor*> m_actors;

public:
	void BeginPlay() override;

	void Tick(float dt) override;
	void Render() override;
};