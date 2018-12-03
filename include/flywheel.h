#ifndef _FLYWHEEL_H_
#define _FLYWHEEL_H_

extern int fwPrevTime;
extern int fwDeltaTime;
extern int fwTics;
extern int fwPrevTics;
extern int fwDeltaTics;
extern int fwVel;

extern int fwError;
extern int fwPrevError;
extern bool fwFirstCross;
extern int fwPower;
extern int fwPowerAtZero;

extern int fwVelGoal;

void initFlywheel();

int getFlywheelVelocity();

void setFlywheelMtr(int power);

void setFlywheelVelocity(int goal, int fwGoalPower);


#endif // _FLYWHEEL_H_
