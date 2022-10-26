#include "Player.hpp"

#include <Novice.h>

#include "BaseData.hpp"
#include "Controller.hpp"

#include "Map.hpp"
#include "Math.hpp"

#include "Entity.hpp"

#include "Bullet.hpp"

//#include"Boss.hpp"



void Player::DrawEntity() {
	AnimationUpdate();

	Novice::DrawLine(position.x, ToWorld(position.y), prePosition.x, ToWorld(prePosition.y), 0xFF0000FF);
	if (nowPolar.theta != prePolar.theta) {
		DrawQuadFunction(position, { radius * 2,radius * 2 }, srcX, srcY, srcW, srcH, textureHandle, Vector2ToPolar((PolarToVector2(nowPolar) - PolarToVector2(prePolar)) * -1).theta, color);
		DrawQuadFunction(prePosition, { radius * 2,radius * 2 }, srcX, srcY, srcW, srcH, textureHandle, Vector2ToPolar((PolarToVector2(nowPolar) - PolarToVector2(prePolar)) * -1).theta, (color & 0xFFFFFF00) + (color & 0xFF) / 2);
	}
	else {
		DrawQuadFunction(position, { radius * 2,radius * 2 }, srcX, srcY, srcW, srcH, textureHandle, nowPolar.theta + Degree2Radian(90) * reverse, color);
	}
}


Player::Player()
{

}


void Player::EntityUpdate() {
	if (!isInput) {
		position += velocity;
		if (
			(Length(PolarToVector2(nowPolar), PolarToVector2(prePolar)))
			<=
			(Length(position, MapCentor + PolarToVector2(nowPolar)))
			)
		{
			//	position = Nomalize(Vector2Difference(PolarToVector2(nowPolar), PolarToVector2(prePolar))) * Clamp((Vector2Difference(PolarToVector2(nowPolar), position)).Length(), 0, (Vector2Difference(PolarToVector2(nowPolar), PolarToVector2(prePolar))).Length());

			position = prePosition;

			if (velocity.Length() != 0) {
				/*reverse *= -1;*/
				BulletShooting();
			}

			velocity = ZeroVector2;
			nowPolar = Vector2ToPolar(position - MapCentor);
			nowPolar.radius = MapRadius;
			prePolar = nowPolar;
			prePosition = MapCentor + PolarToVector2(prePolar);
		}
	}
}


void Player::BulletShooting() {

	for (int i = 0; i < Bullet::BulletMaxCount; i++) {		//バレットスポーン関数
		if (!Bullet::bullet[i].isAlive) {
			Bullet::bullet[i].isAlive = true;
			Bullet::bullet[i].velocity = this->velocity;
			Bullet::bullet[i].position = this->position;

			break;
		}
	}

}

void Player::Reset(int count) {
	*this = Player(Novice::LoadTexture("./Resources/Texture/Entity/Player/Idle/love.png"), 152, 152, 0, 1);

	position = MiddleCentor;
	velocity.Reset();
	radius = 32;

	speed = 30;

	nowPolar.radius = MapRadius;
	switch (count) {
	case 0:
		nowPolar.theta = Degree2Radian(0);
		break;
	case 1:
		if (playerCount == 2) {
			nowPolar.theta = Degree2Radian(180);
		}
		else {
			nowPolar.theta = Degree2Radian(120);
		}
		break;
	case 2:
		nowPolar.theta = Degree2Radian(240);
		break;
	}
	prePolar = nowPolar;

	position = MapCentor + PolarToVector2(nowPolar);
	prePosition = position;
}

//void Player::BossAttackHit() {
//	if (Ellipse2LineLength(position, Boss::statePosition, Boss::endPosition) == radius) {
//		Boss::AttackReset();
//		Boss::hp -= 1;
//	}
//}

