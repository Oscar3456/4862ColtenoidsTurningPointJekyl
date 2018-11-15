#include "main.h"
#include "catapult.h"

int error;
int integral;

void setCatapultMtr(int power){
  motorSet(CATAPULT_A_MTR, power);
  motorSet(CATAPULT_B_MTR, power);
}

int calculateCatapultPID(int posGoal){
  error = posGoal - getCatapultPot(); // calculate error

  if(abs(error) < CATAPULT_INTEGRAL_RANGE && abs(error) > CATAPULT_ZEROED_RANGE){ // if in range, calculate integral
    integral += error;
  } else {
    integral = 0;
  }

  return ((error * CATAPULT_KP) + (integral * CATAPULT_KI)); // set motors
}
