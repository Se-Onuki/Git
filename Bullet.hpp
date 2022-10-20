#pragma once
#include "Entity.hpp"

#include"Enemy.hpp"

class BulletClass :public Entity
{
public:
	BulletClass();
	using Entity::Entity;

private:

};


class Bullet
{
public:
	Bullet();

	static const int BulletMaxCount = 128;

	static BulletClass bullet[BulletMaxCount];

	static void DrawBullet();

	static void BulletEnemyHit();
	static void BulletDelete();
	static void BulletUpdate();

	static void BulletReset();

	static void Reset(int index);

	float a;
	float b;
	float distance;
private:

};

inline void Bullet::BulletEnemyHit() {
	for (int i = 0; i < BulletMaxCount; i++) {
		for (int j = 0; j < EnemyMax; j++) {
			if (BallCollision(bullet[i].position, bullet[i].radius, enemy[j].position, enemy[j].radius)) {
				enemy[j].Reset();
				Novice::DrawEllipse(0, 0, 10, 10, 0.0f, GREEN, kFillModeSolid);
			}
		}
	}

}
