#include "math.h"

#define PI 3.1415926 

Vector3 Add(Vector3 src, Vector3 dst)
{
    Vector3 sum;
    sum.x = src.x + dst.x;
    sum.y = src.y + dst.y;
    sum.z = src.z + dst.z;
    return sum;
}

Vector3 Subtract(Vector3 src, Vector3 dst)
{
    Vector3 diff;
    diff.x = src.x - dst.x;
    diff.y = src.y - dst.y;
    diff.z = src.z - dst.z;
    return diff;
}

Vector3 Divide(Vector3 src, float num)
{
    Vector3 vec;
    vec.x = src.x / num;
    vec.y = src.y / num;
    vec.z = src.z / num;

    return vec;
}

float RadianToDegree(float radian)
{
    return radian * (180 / PI);
}

float DegreeToRadian(float degree)
{
    return degree * (PI / 180);

}

Vector3 RadianToDegree(Vector3 radians)
{
    Vector3 degrees;
    degrees.x = radians.x * (180 / PI);
    degrees.y = radians.y * (180 / PI);
    degrees.z = radians.z * (180 / PI);
    return degrees;
}

Vector3 DegreeToRadian(Vector3 degrees)
{
    Vector3 radians;
    radians.x = degrees.x * (PI / 180);
    radians.y = degrees.y * (PI / 180);
    radians.z = degrees.z * (PI / 180);
    return radians;
}

float DotProduct(Vector3 src, Vector3 dst)
{
    return src.x * dst.x + src.y * dst.y + src.z * dst.z;
}

float Magnitude(Vector3 vec)
{
    return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float Distance(Vector3 src, Vector3 dst)
{
    Vector3 diff = Subtract(src, dst);
    return Magnitude(diff);
}

void ClampAngle(Vector3& angle) {
    if (angle.x > 89.0f) angle.x = 89.f;
    if (angle.x < -89.0f) angle.x = -89.f;

    if (angle.y > 180.f) angle.y = 180.f;
    if (angle.y < -180.f) angle.y = -180.f;

    angle.z = 0.0f;
}

void Normalise(Vector3& angle) {
    if (angle.x > 89.0f) angle.x -= 180.0f;
    if (angle.x < -89.0f) angle.x += 180.0f;

    while (angle.y > 180) angle.y -= 360.f;
    while (angle.y < -180) angle.y += 360.f;
}

Vector3 CalcAngle(Vector3 src, Vector3 dst)
{
    Vector3 angles;

    Vector3 delta = Subtract(src, dst);
    float hyp = Magnitude(Subtract(src, dst));
    angles.x = atanf(delta.z / hyp) * 180.0f / PI;
    angles.y = atanf(delta.y / delta.x) * 180.0f / PI;
    angles.z = 0.0f;

    if (delta.x >= 0.0f)
        angles.y += 180.0f;

    return angles;
}
