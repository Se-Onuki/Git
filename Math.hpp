#pragma once

#include"Vector2.hpp"
#include "PolarCoordinates.hpp"

/// <summary>
/// �񎟌����ϊ֐�
/// </summary>
/// <param name="startA">����A�̎n�_</param>
/// <param name="endA">����A�̏I�_</param>
/// <param name="startB">����B�̎n�_</param>
/// <param name="endB">����B�̏I�_</param>
/// <param name="normalizeFlagA"></param>
/// <param name="normalizeFlagB"></param>
/// <returns>���όv�Z�̌���</returns>
float DotProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB);

/// <summary>
/// �񎟌����ϊ֐�
/// </summary>
/// <param name="VectorA">�x�N�g��A</param>
/// <param name="VectorB">�x�N�g��B</param>
/// <returns>���όv�Z�̌���</returns>
float DotProduct(Vector2 VectorA, Vector2 VectorB);


/// <summary>
/// �񎟌��O�ϊ֐�
/// </summary>
/// <param name="startA">����A�̎n�_</param>
/// <param name="endA">����A�̏I�_</param>
/// <param name="startB">����B�̎n�_</param>
/// <param name="endB">����B�̏I�_</param>
/// <param name="normalizeFlagA"></param>
/// <param name="normalizeFlagB"></param>
/// <returns>���όv�Z�̌���</returns>
float CrossProduct(Vector2 startA, Vector2 endA, Vector2 startB, Vector2 endB);


/// <summary>
/// �񎟌��O�ϊ֐�
/// </summary>
/// <param name="VectorA">�x�N�g��A</param>
/// <param name="VectorB">�x�N�g��B</param>
/// <returns>���όv�Z�̌���</returns>
float CrossProduct(Vector2 VectorA, Vector2 VectorB);



/// <summary>
/// �ʓx�@��x���@�ɂ���
/// </summary>
/// <param name="radian">�ʓx�@</param>
/// <returns>�x���@</returns>
float Radian2Degree(float radian);

/// <summary>
/// �x���@���ʓx�@�ɂ���
/// </summary>
/// <param name="degree">�x���@</param>
/// <returns>�ʓx�@</returns>
float Degree2Radian(float degree);




/// <summary>
/// �ɍ��W�n���x�N�g���ɕϊ�����B
/// </summary>
/// <param name="Polar">�ɍ��W</param>
/// <returns>�x�N�g��</returns>
Vector2 PolarToVector2(PolarCoordinates Polar);

/// <summary>
/// �x�N�g�����ɍ��W�n�ɕϊ�����B
/// </summary>
/// <param name="Vector">�x�N�g��</param>
/// <returns>�ɍ��W�N���X</returns>
PolarCoordinates Vector2ToPolar(Vector2 Vector);
