#include "Particle.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include "Vector2.hpp"
#include "Matrix2x2.hpp"

#include "Easing.hpp"
#include "Math.hpp"

#include "SpriteClass.hpp"


ParticleClass::ParticleClass():aliveFlame(0), maxFlame(0)
{
}

Particle::Particle()
{

}

void Particle::Spawn(const Vector2& Position) {
	for (int i = 0; i < ParticleMax; i++) {
		if (!particles[i].isAlive) {
			particles[i].velocity = PolarToVector2({ (float)(GetRandom(0,3)),(float)(Degree2Radian(GetRandom(0,359))) });
			particles[i].position = Position;
			particles[i].radius = GetRandom(5, 15);
			particles[i].maxFlame = GetRandom(40, 60);

			particles[i].isAlive = true;
			break;
		}
	}
}


void Particle::Spawn(const Vector2& Position, unsigned int needSpawn) {
	int spawnedCount = 0;
	for (int i = 0; i < ParticleMax && spawnedCount <= needSpawn; i++) {
		if (!particles[i].isAlive) {
			particles[i].velocity = PolarToVector2({ (float)(GetRandom(0,3)),(float)(Degree2Radian(GetRandom(0,359))) });
			particles[i].position = Position;
			particles[i].radius = GetRandom(5, 15);
			particles[i].maxFlame = GetRandom(40, 60);

			particles[i].isAlive = true;
			spawnedCount++;
		}
	}
}


void Particle::Spawn(const Vector2& Position, unsigned int needSpawn, unsigned int color) {
	int spawnedCount = 0;
	for (int i = 0; i < ParticleMax && spawnedCount <= needSpawn; i++) {
		if (!particles[i].isAlive) {
			this->particles[i].color = color;

			particles[i].velocity = PolarToVector2({ (float)(GetRandom(0,3)),(float)(Degree2Radian(GetRandom(0,359))) });
			particles[i].position = Position;
			particles[i].radius = GetRandom(5, 15);
			particles[i].maxFlame = GetRandom(40, 60);

			particles[i].isAlive = true;
			spawnedCount++;
		}
	}
}


void Particle::Update() {


	//�p�[�e�B�N���ɑ��x�Ǝ��������Z
	for (int i = 0; i < ParticleMax; i++) {
		if (particles[i].isAlive) {
			particles[i].position += particles[i].velocity;//velocity�����Z
			particles[i].aliveFlame++;//�������Ԃ����Z

			particles[i].color = (particles[i].color & 0xFFFFFF00) + ColorEasingMove(0xFF, 0x00, (float)(particles[i].aliveFlame) / particles[i].maxFlame);//���񂾂񓧖��ɂ��Ă���
		}

		if (particles[i].isAlive) {
			CheckDelete(i);
		}
	}
}

void Particle::CheckDelete() {

	for (int i = 0; i < ParticleMax; i++) {
		OffScreen(i);
		LifeEnd(i);
	}
}

void Particle::CheckDelete(int index) {
		OffScreen(index);
		LifeEnd(index);
}

void Particle::OffScreen(int index) {
//	if (pos.x + radius.x < 0 || pos.x + radius.x + screen.x > ScreenSize.x || pos.y + radius.y<0 || pos.y + radius.y + screen.y >  ScreenSize.y) {

	if (!isInner(0- particles[index].radius, < , particles[index].position.x , < , ScreenSize.x + particles[index].radius) || !isInner(0 - particles[index].radius, < , particles[index].position.y, < , ScreenSize.y + particles[index].radius)) {
		Reset(index);
	}
}

void Particle::LifeEnd(int index) {
	//�p�[�e�B�N���̎����̔���Ə�����
		if (particles[index].aliveFlame > particles[index].maxFlame) {
			Reset(index);
		}

}

void Particle::Reset(int index) {

	particles[index].textureHandle = TestWhiteTexture;
	particles[index].srcH = 128;
	particles[index].srcW = 128;
	particles[index].needNextFlame = 30;
	particles[index].maxFlame = 2;


	particles[index].isAlive = false;
	particles[index].position = MiddleCentor;
	particles[index].aliveFlame = 0;
	particles[index].color = 0x00FF00FF;
}

void Particle::Draw() {
	for (int i = 0; i < ParticleMax; i++)
	{
		if (particles[i].isAlive) {
			particles[i].AnimationUpdate();
			particles[i].DrawEntity();
			//DrawQuadFunction(particles[i].position, { particles[i].radius * 2,particles[i].radius * 2 }, particles[i].srcX, particles[i].srcY, particles[i].srcW, particles[i].srcH, particles[i].textureHandle, Vector2ToPolar(particles[i].velocity).theta, particles[i].color);
			//	Novice::DrawEllipse(particles[i].position.x, ToWorld(particles[i].position.y), particles[i].radius, particles[i].radius, 0.0f, particles[i].color, kFillModeSolid);
		}
	}
}