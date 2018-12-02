#ifndef _DESCORER_H_
#define _DESCORER_H_

extern int descorerMtrGoal;
extern int descorerPosGoal;
extern bool descorerPIDEnabled;

void initDescorer();

void setDescorerMtr(int power);

void setDescorerPos(int posGoal);

int getDescorerEnc();

void descorerCtrl();

#endif // _DESCORER_H_
