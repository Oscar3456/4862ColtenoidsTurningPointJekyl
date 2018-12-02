#ifndef _POSTRACKING_H_
#define _POSTRACKING_H_

void trackPos();

int degreeToRad(int degrees);

void driveToPos(int x, int y, float maxVel);

void turnToAngle(float angle, float maxVel);

#endif // _POSTRACKING_H_
