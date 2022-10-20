//#include"Boss.hpp"
//
//#include "BaseData.hpp"
//#include "Camera.hpp"
//
//#include "Math.hpp"
//#include "PolarCoordinates.hpp"
//#include "Vector2.hpp"
//
//#include "Map.hpp"
//
//Boss::Boss() {
//
//}
//
//void Boss::Reset() {
//	position = MiddleCentor;
//	radius = 256;
//
//	textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/Arrow.png");
//	srcH = 128;
//	srcW = 128;
//	needNextFlame = 30;
//	maxFlame = 2;
//
//	isAlive = false;
//}
//
//void Boss::Spawn() {
//
//	textureHandle = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/Arrow.png");
//	srcH = 128;
//	srcW = 128;
//
//	needNextFlame = 180;
//	maxFlame = 2;
//
//	radius = 256;
//	color = 0xFFFFFFFF;
//
//
//	PolarCoordinates test;
//
//	test.radius = GetRandom(MapRadius * 2, MapRadius * 2.5);
//
//	test.theta = Degree2Radian(GetRandom(0, 360));
//
//	position = statePosition;
//
//	speed = 2;
//
//	if (count > 60) {
//		velocity = Nomalize((PolarToVector2(test) * -1)) * speed;
//
//	}
//	
//
//	isAlive = true;
//}
//
//
//
//void Boss::Despawn() {
//
//	
//}
//
//void Boss::HitCore() {
//	if (BallCollision(position, radius, MapCentor, 30)) {
//		Camera::Shake({ 20,20 }, 30);
//		Reset();
//	}
//}
//
//void Boss::AttackSpawn() {
//	if (endPosition.y > 0) {
//		nowEndPosition.y -= 10;
//	}
//
//	statePosition.x = GetRandom(MiddleCentor.x - MapRadius, MiddleCentor.x + MapRadius);
//	statePosition.y = ScreenSize.y;
//
//	endPosition.x= GetRandom(MiddleCentor.x - MapRadius, MiddleCentor.x + MapRadius);
//	endPosition.y = statePosition.y + nowEndPosition.y;
//
//	if (flame % 120 == 0 && flame != 0 && !attackFlag) {
//		attackFlag = true;
//	}
//}
//
//void Boss::Attack() {
//	
//
//	Novice::DrawLine(statePosition.x, statePosition.y, endPosition.x, endPosition.y, 0xff00ffff);
//
//	count++;
//
//	            
//
//}
//
//void Boss::AttackReset() {
//	Camera::Shake({ 20,20 }, 10);
//
//	attackFlag = false;
//	statePosition = {};
//	endPosition = {};
//}