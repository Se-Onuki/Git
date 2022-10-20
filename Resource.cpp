#include "Resource.hpp"

#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "BaseData.hpp"
#include "Math.hpp"
#include "Vector2.hpp"

#include "Camera.hpp"

#include "SpriteClass.hpp"


float ToWorld(float y) {
	return (-(y)+WorldPos);
};

void DrawQuadFunction(Vector2 centor, Vector2 size, int srcX, int srcY, int srcW, int srcH, unsigned int textureHandle, unsigned int color) {
	Novice::DrawQuad((centor.x - Camera::scroll.x) - ((size.x) / 2), ToWorld((centor.y - Camera::scroll.y) + ((size.y) / 2)), (centor.x - Camera::scroll.x) + ((size.x) / 2), ToWorld((centor.y - Camera::scroll.y) + ((size.y) / 2)), (centor.x - Camera::scroll.x) - ((size.x) / 2), ToWorld((centor.y - Camera::scroll.y) - ((size.y) / 2)), (centor.x - Camera::scroll.x) + ((size.x) / 2), ToWorld((centor.y - Camera::scroll.y) - ((size.y) / 2)), srcX, srcY, srcW, srcH, textureHandle, color);
};

void DrawQuadFunction(Vector2 centor, Vector2 size, int srcX, int srcY, int srcW, int srcH, unsigned int textureHandle, float angle, unsigned int color) {
	Vector2 LeftTop = RotateVector2((size * 0.5), Degree2Radian( + 0) + angle);
	Vector2 LeftDown = RotateVector2((size * 0.5), Degree2Radian( + 90) + angle);
	Vector2 RightTop = RotateVector2((size * 0.5), Degree2Radian( + 270) + angle);
	Vector2 RightDown = RotateVector2((size * 0.5), Degree2Radian( + 180) + angle);
	Novice::DrawQuad((centor.x - Camera::scroll.x) + LeftTop.x, ToWorld((centor.y - Camera::scroll.y) + LeftTop.y), (centor.x - Camera::scroll.x) + RightTop.x, ToWorld((centor.y - Camera::scroll.y) + RightTop.y), (centor.x - Camera::scroll.x) + LeftDown.x, ToWorld((centor.y - Camera::scroll.y) + LeftDown.y), (centor.x - Camera::scroll.x) + RightDown.x, ToWorld((centor.y - Camera::scroll.y) + RightDown.y), srcX, srcY, srcW, srcH, textureHandle, color);
};