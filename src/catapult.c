#include "main.h"
#include "catapult.h"



int error;
int integral;

int catapultMtrGoal;
int catapultPosGoal;
bool catapultPIDEnabled;

int catapultOffset;

void initCatapult(){
  catapultOffset = analogRead(CATAPULT_POT);
}

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
