#pragma once

#include "BaseData.hpp"
#include "Vector2.hpp"

#include "Entity.hpp"

#include "SpriteClass.hpp"

const unsigned int ParticleMax = 128;

/// <summary>
	/// Ball�N���X
	/// </summary>
	/// <param name="position">�ʒu�x�N�g��</param>
	/// <param name="velocity">�ړ����x�x�N�g��</param>
	/// <param name="acceleration">�����x�x�N�g��</param>
	/// <param name="radius">���a</param>
	/// <param name="norm">�m����</param>
	/// <param name="mass">�d��</param>
	/// <param name="color">�F 0xRRGGBBAA</param>
	/// <param name="aliveFlame">��������</param>
	/// <param name="maxFlame">����</param>
	/// <param name="isAlive">�����̐^�U�l</param>
class ParticleClass:public Entity{
public:
	int aliveFlame;
	int maxFlame;

	ParticleClass();
};

class Particle
{
public:
	Particle();

	ParticleClass particles[ParticleMax];

	void Spawn(const Vector2& Position);
	void Spawn(const Vector2& Position, unsigned int count);
	void Spawn(const Vector2 &Position, unsigned int needSpawn, unsigned int color);

	void Update();

	void CheckDelete();
	void CheckDelete(int index);

	//��ʊO�ɏo���Ƃ�
	void OffScreen(int index);
	void LifeEnd(int index);

	void Reset(int index);


	void Draw();

private:

};






