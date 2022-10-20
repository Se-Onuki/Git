#pragma once

#include "Vector2.hpp"

// �萔�錾

/// �X�N���[�����W�ƃ��[���h���W�ő��ݕϊ����錴�_
const int WorldPos = ScreenSize.y;



/// <summary>
/// �X�N���[�����W�ƃ��[���h���W�ő��ݕϊ�����֐��B
/// </summary>
/// <param name="y">�ϊ��������l</param>
/// <returns>�ϊ���̒l</returns>
float ToWorld(float y);




/// <summary>
	/// �l�p�`�`��
	/// </summary>
	/// <param name="centor">�`�悷��l�p�`�̒��S���W</param>
	/// <param name="size">�`�悷��l�p�`�̑傫��</param>
	/// <param name="srcX">�摜��̕`�悵�����͈͍�����W X</param>
	/// <param name="srcY">�摜��̕`�悵�����͈͍�����W Y</param>
	/// <param name="srcW">�摜��̕`�悵�����͈͉���</param>
	/// <param name="srcH">�摜��̕`�悵�����͈͏c��</param>
	/// <param name="textureHandle">�e�N�X�`���̃n���h��</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
void DrawQuadFunction(Vector2 centor, Vector2 size, int srcX, int srcY, int srcW, int srcH, unsigned int textureHandle, unsigned int color);


/// <summary>
	/// �l�p�`�`��
	/// </summary>
	/// <param name="centor">�`�悷��l�p�`�̒��S���W</param>
	/// <param name="size">�`�悷��l�p�`�̑傫��</param>
	/// <param name="srcX">�摜��̕`�悵�����͈͍�����W X</param>
	/// <param name="srcY">�摜��̕`�悵�����͈͍�����W Y</param>
	/// <param name="srcW">�摜��̕`�悵�����͈͉���</param>
	/// <param name="srcH">�摜��̕`�悵�����͈͏c��</param>
	/// <param name="textureHandle">�e�N�X�`���̃n���h��</param>
	/// <param name="angle">�`��̉�]�p(rad)</param>
	/// <param name="color">�`�悷��X�v���C�g�̐F</param>
void DrawQuadFunction(Vector2 centor, Vector2 size, int srcX, int srcY, int srcW, int srcH, unsigned int textureHandle, float angle, unsigned int color);
