#pragma once

#define functionEasing(start , end, easingVolume, easingType)  easingMove(start, end, easingType(easingVolume))
#define easePlane(number) number

float easingMove(float start, float end, float easingVolume);


int intEasingMove(long int start, long int end, float easingVolume);

unsigned int ColorEasingMove(unsigned int statColor, unsigned int endColor, float easingVolume);


float easeLinear(float number);
float easeOutBack(float x);
float easeInBack(float x);
float easeOutCirc(float x);
float easeInCirc(float x);
float easeInSine(float x);
float easeOutSine(float x);
float easeInExpo(float x);
float easeOutExpo(float x);
