#include "Enemy.hpp"


#include "BaseData.hpp"
#include "Camera.hpp"

#include "Math.hpp"
#include "PolarCoordinates.hpp"
#include "Vector2.hpp"

#include "Map.hpp"

Enemy::Enemy() 
{

}

void Enemy::Reset() {
	position = MiddleCentor;
	radius = 32;

	textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/Arrow.png");
	srcH = 128;
	srcW = 128;
	needNextFlame = 30;
	maxFlame = 2;

	isAlive = false;
}

void Enemy::Spawn() {

	textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/Arrow.png");
	srcH = 128;
	srcW = 128;

	needNextFlame = 30;
	maxFlame = 2;

    radius = 32;
	color = 0xFFFFFFFF;


	PolarCoordinates test;

	test.radius = GetRandom(MapRadius * 2,MapRadius * 2.5);

	test.theta = Degree2Radian(GetRandom(0, 360));

	position = PolarToVector2(test) + MapCentor;

	speed = 2;

	velocity = Nomalize((PolarToVector2(test) * -1)) * speed;

	isAlive = true;
}

void EnemySpawn() {
	for (int i = 0; i < EnemyMax; i++) {
		if (!enemy[i].isAlive) {
			enemy[i].Spawn();
			break;
		}
	}
}

void Enemy::Despawn() {

	if (isAlive) {
		HitCore();
	}
}

void Enemy::HitCore() {
	if (BallCollision(position, radius, MapCentor, 30)) {
		Camera::Shake({ 20,20 }, 30);
		Reset();
	}
}