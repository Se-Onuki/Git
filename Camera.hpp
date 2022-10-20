#pragma once

#include "Vector2.hpp"


class Camera
{
public:
	Camera();

	static Vector2 scrollReference; // �X�N���[���l
	static Vector2 scroll;			// ������X�N���[���l

	static void Reset();
	static void PositionReset();
	static void EffectReset();

	static void Shake(Vector2 radius, unsigned int flame);

	static void Update();

private:

	static Vector2 shakeRadius;
	static unsigned int maxShakeFlame;
	static unsigned int shakeFlame;

};
