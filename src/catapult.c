#include "main.h"
#include "catapult.h"



int catapultPower;

float kP = 1;
float kI = 1;
int error;
int integral;
int integralRange;

void setCatapultMtr(int power){
  motorSet(CATAPULT_A_MTR, power);
  motorSet(CATAPULT_B_MTR, power);
}

void setCatapultPos(int posGoal){
  error = posGoal - getCatapultPot(); // calculate error

  if(abs(error) < integralRange){ // if in range, calculate integral
    integral += error;
  } else {
    integral = 0;
  }

  setCatapultMtr((error * kP) + (integral * kI)); // set motors
}
