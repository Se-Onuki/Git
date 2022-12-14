#pragma once

#include <Novice.h>

static unsigned int TestWhiteTexture;
static unsigned int TestCircleTexture;
static unsigned int TestUVTexture;


static int PlayerGuide;

static int TextureFlame = 0;

/// <summary>
	/// Spriteクラス
	/// </summary>
	/// <param name="textureHandle">テクスチャ</param>
	/// <param name="srcX">画像上の描画したい範囲左上座標 X</param>
	/// <param name="srcY">画像上の描画したい範囲左上座標 Y</param>
	/// <param name="srcW">画像上の描画したい範囲横幅</param>
	/// <param name="srcH">画像上の描画したい範囲縦幅</param>
class SpriteClass
{
public:
	SpriteClass();
	SpriteClass(unsigned int textureHandle, int srcW, int srcH, unsigned int needNextFlame, unsigned int maxFlame);

	unsigned int textureHandle;
	int srcX; // 画像上の描画したい範囲左上座標 X
	int srcY; // 画像上の描画したい範囲左上座標 Y
	int srcW; // 画像上の描画したい範囲横幅
	int srcH; // 画像上の描画したい範囲縦幅
	unsigned int needNextFlame;
	unsigned int maxFlame;

	static int useFlamePointer;

	void AnimationUpdate();

private:

};


static void ImportTexture() {
	TestWhiteTexture = Novice::LoadTexture("white1x1.png");
	TestCircleTexture = Novice::LoadTexture("./Resources/Texture/TestTexture/Circle.png");
	TestUVTexture = Novice::LoadTexture("uvChecker.png");

	PlayerGuide = Novice::LoadTexture("./Resources/Texture/Entity/Enemy/Arrow.png");
}

inline void TextureUpdate() {
	SpriteClass::useFlamePointer++;
	TextureFlame++;
}