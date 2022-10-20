#pragma once
#include "Entity.hpp"

class Enemy : public Entity
{
public:
	Enemy();
	using Entity::Entity;

	void Reset();

	void Spawn();

	int interval = 30;
	
	void Despawn();

	void HitCore();
};
const int EnemyMax = 100;

static Enemy enemy[EnemyMax] = {};
void EnemySpawn();

static int killCount;