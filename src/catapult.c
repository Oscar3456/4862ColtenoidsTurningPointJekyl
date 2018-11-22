#include "main.h"
#include "catapult.h"

int error;
int integral;

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
  if(abs(error) < CATAPULT_INTEGRAL_RANGE && abs(error) > 20){ // if in range, calculate integral
    integral += error;
  } else {
    integral = 0;
  }*/

  setCatapultMtr((error * CATAPULT_KP));// + (integral * CATAPULT_KI)); // set motors
}
