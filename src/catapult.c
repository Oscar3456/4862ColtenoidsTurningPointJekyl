#include "main.h"
#include "catapult.h"



int error;
int integral;

int catapultMtrGoal;
int catapultMtrCurrent;
bool catapultSlewEnabled;
int catapultPosGoal;
bool catapultPIDEnabled;

int catapultOffset;

void initCatapult(){
  catapultOffset = analogRead(CATAPULT_POT);
}

void setCatapultMtr(int mtrGoal){
    if(catapultSlewEnabled){
    if(catapultMtrCurrent + CATAPULT_SLEW < mtrGoal){
      catapultMtrCurrent += CATAPULT_SLEW;
    } else if(catapultMtrCurrent - CATAPULT_SLEW > mtrGoal){
      catapultMtrCurrent -= CATAPULT_SLEW;
    } else{
      catapultMtrCurrent = mtrGoal;
    }
  } else {
    catapultMtrCurrent = catapultMtrGoal;
  }
  motorSet(CATAPULT_A_MTR, catapultMtrCurrent);
  motorSet(CATAPULT_B_MTR, catapultMtrCurrent);
}

void setCatapultPos(int posGoal){

  error = posGoal - getCatapultPot(); // calculate error
/*
  if(abs(error) < CATAPULT_INTEGRAL_RANGE){ // if in range, calculate integral
    integral += error;
  } else {
    integral = 0;
  }

  catapultMtrGoal = (error * 0.55) + (integral * 0.001); // set motors*/

  if (getCatapultPot() > posGoal + 20){
    catapultMtrGoal = - 110;
  } else  if (getCatapultPot() > posGoal){
      catapultMtrGoal = - 30;
    }else {
    catapultMtrGoal = -10;
  }
}

void catapultCtrl(){

  //while(1){
    if(catapultPIDEnabled){
      setCatapultPos(catapultPosGoal);
    }
    setCatapultMtr(catapultMtrGoal);
  //}
}

int getCatapultPot(){
  return analogRead(CATAPULT_POT) - catapultOffset;
}
