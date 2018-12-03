#ifndef _DRIVE_H_
#define _DRIVE_H_

extern float angleStart;
extern float leftStart;
extern float rightStart;

extern int rightMtrGoal;
extern int leftMtrGoal;

void initDrive();

float getLeftEnc();

float getRightEnc();

float getEncAngle();

void startDriveStraight();

float degreesToRad(int degrees);

void basicDriveStraight(float distance);

void setDriveMtr(int leftPower, int rightPower);

void driveCtrl();

#endif // _DRIVE_H_
