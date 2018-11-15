#include "main.h"
#include "descorer.h"

int error;

void setDescorerMtr(int power){
  if (getDescorerEnc() < DESCORER_MIN || getDescorerEnc() > DESCORER_MAX){
    power = 0;
  }
  motorSet(DESCORER_MTR, power);
}

int calculateDescorerPID(int posGoal){
  error = posGoal - getDescorerEnc();
  return error * DESCORER_KP;
}
