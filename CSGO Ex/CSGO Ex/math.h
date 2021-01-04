#pragma once
#include <iostream>
#include <cmath> 

#define PI 3.1415926 

struct Vector3
{
	float x, y, z;
};

Vector3 Add(Vector3 src, Vector3 dst);

Vector3 Subtract(Vector3 src, Vector3 dst);

Vector3 Divide(Vector3 src, float num);

float RadianToDegree(float radian);

float DegreeToRadian(float degree);

Vector3 RadianToDegree(Vector3 radians);

Vector3 DegreeToRadian(Vector3 degrees);

float DotProduct(Vector3 src, Vector3 dst);

float Magnitude(Vector3 vec);

float Distance(Vector3 src, Vector3 dst);

void ClampAngle(Vector3& angle);

void Normalise(Vector3& angle);

Vector3 CalcAngle(Vector3 src, Vector3 dst);
