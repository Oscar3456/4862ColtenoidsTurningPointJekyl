#ifndef _POSTRACKING_H_
#define _POSTRACKING_H_

extern float globalX;
extern float globalY;
extern float globalAngle;

void trackPos();

float degreeToRad(float degrees);

float radToDegrees(float rad);

void driveToPos(int x, int y, float maxVel);

void turnToAngle(float angle, float maxVel);

#endif // _POSTRACKING_H_
