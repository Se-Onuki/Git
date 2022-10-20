#pragma once

#include <Novice.h>

static unsigned int TestWhiteTexture;
static unsigned int TestCircleTexture;
static unsigned int TestUVTexture;

static int TextureFlame = 0;

/// <summary>
	/// Sprite�N���X
	/// </summary>
	/// <param name="textureHandle">�e�N�X�`��</param>
	/// <param name="srcX">�摜��̕`�悵�����͈͍�����W X</param>
	/// <param name="srcY">�摜��̕`�悵�����͈͍�����W Y</param>
	/// <param name="srcW">�摜��̕`�悵�����͈͉���</param>
	/// <param name="srcH">�摜��̕`�悵�����͈͏c��</param>
class SpriteClass
{
public:
	SpriteClass();
	SpriteClass(unsigned int textureHandle, int srcW, int srcH, unsigned int needNextFlame, unsigned int maxFlame);

	unsigned int textureHandle;
	int srcX; // �摜��̕`�悵�����͈͍�����W X
	int srcY; // �摜��̕`�悵�����͈͍�����W Y
	int srcW; // �摜��̕`�悵�����͈͉���
	int srcH; // �摜��̕`�悵�����͈͏c��
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
}

inline void TextureUpdate() {
	SpriteClass::useFlamePointer++;
	TextureFlame++;
}