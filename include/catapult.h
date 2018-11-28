#ifndef _CATAPULT_H_
#define _CATAPULT_H_

extern int catapultMtrGoal;
extern int catapultPosGoal;
extern bool catapultPIDEnabled;

void setCatapultMtr(int power);

void setCatapultPos(int posGoal);

void catapultCtrl();

int getCatapultPot();

#endif // _CATAPULT_H_
