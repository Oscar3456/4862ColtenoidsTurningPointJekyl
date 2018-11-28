#include "main.h"
#include "catapult.h"



int error;
int integral;

int catapultMtrGoal;
int catapultPosGoal;
bool catapultPIDEnabled;

void setCatapultMtr(int power){
  if(power < -127){
    power = -127;
  } else if (power > 127){
    power = 127;
  }
  motorSet(CATAPULT_A_MTR, power);
  motorSet(CATAPULT_B_MTR, power);
}

void setCatapultPos(int posGoal){
/*
  error = posGoal - getCatapultPot(); // calculate error

  if(abs(error) < CATAPULT_INTEGRAL_RANGE){ // if in range, calculate integral
    integral += error;
  } else {
    integral = 0;
  }

  catapultMtrGoal = (error * 0.55) + (integral * 0.001); // set motors*/

  if (getCatapultPot() > posGoal){
    catapultMtrGoal = -110;
  } else {
    catapultMtrGoal = 0;
  }
}

void catapultCtrl(){
  analogCalibrate(CATAPULT_POT);
  while(1){
    if(catapultPIDEnabled){
      setCatapultPos(catapultPosGoal);
    }
    setCatapultMtr(catapultMtrGoal);
  }
}

int getCatapultPot(){
  return analogReadCalibrated(CATAPULT_POT);
}
