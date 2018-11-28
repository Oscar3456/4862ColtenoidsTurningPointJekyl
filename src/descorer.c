#include "main.h"
#include "descorer.h"

  Encoder descorerEnc;

int error;

int descorerMtrGoal;
int descorerPosGoal;
bool descorerPIDEnabled;

void setDescorerMtr(int power){
  if (getDescorerEnc() < DESCORER_MIN || getDescorerEnc() > DESCORER_MAX){
    power = 0;
  }
  motorSet(DESCORER_MTR, power);
}

void setDescorerPos(int posGoal){
  error = posGoal - getDescorerEnc();
  descorerMtrGoal = (error * DESCORER_KP);
}

int getDescorerEnc(){
  return encoderGet(descorerEnc);
}

void descorerCtrl(){

  descorerEnc = encoderInit(DESCORER_ENC_TOP, DESCORER_ENC_BOT, false);
  while(1){
    if(descorerPIDEnabled){
      setDescorerPos(descorerPosGoal);
    }
    setDescorerMtr(descorerMtrGoal);
    wait(20);
  }
}
