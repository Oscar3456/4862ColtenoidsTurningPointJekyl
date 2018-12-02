#ifndef _CATAPULT_H_
#define _CATAPULT_H_

extern int catapultMtrGoal;
extern int catapultMtrCurrent;
extern bool catapultSlewEnabled;
extern int catapultPosGoal;
extern bool catapultPIDEnabled;
extern int catapultOffset;

void initCatapult();

void setCatapultMtr(int mtrGoal);

void setCatapultPos(int posGoal);

void catapultCtrl();

int getCatapultPot();

#endif // _CATAPULT_H_
