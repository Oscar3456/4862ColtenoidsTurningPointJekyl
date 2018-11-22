#include "main.h"
#include "descorer.h"

int error;

void setDescorerMtr(int power){
  if (getDescorerEnc() < DESCORER_MIN || getDescorerEnc() > DESCORER_MAX){
    //power = 0;
  }
  motorSet(DESCORER_MTR, power);
}

void setDescorerPos(int posGoal){
  error = posGoal - getDescorerEnc();
  setDescorerMtr(error * DESCORER_KP);
}
