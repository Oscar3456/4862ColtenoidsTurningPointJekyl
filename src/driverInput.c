#include "main.h"
#include "driverInput.h"

int getInputLeftDrive(){
  int linear = joystickGetAnalog(1, 2) + joystickGetAnalog(1, 1);
  if (abs(linear) < 5){
    linear = 0;
  }
  return linear;
}

int getInputRightDrive(){
  int linear = joystickGetAnalog(1, 2) - joystickGetAnalog(1, 1);
  if (abs(linear) < 5){
    linear = 0;
  }
  return linear;
}

int getInputCatapultState(){
  int state; // 2 to fire, 1 to be ready, 0 to be up
  if(joystickGetDigital(1, 5, JOY_UP)){
    state = 2;
  } else if (joystickGetDigital(1, 5, JOY_DOWN)){
    state = 0;
  } else{
    state = 1;
  }
  return state;
}

int getInputDescorer(){
  int linear = joystickGetAnalog(1, 3);
  if (abs(linear) < 5){
    linear = 0;
  }
  return linear;
}

int getInputBallIntake(){
  int power = 0;
  if(joystickGetDigital(1, 6, JOY_UP)){
    power = BALL_INTAKE_POWER;
  } else if (joystickGetDigital(1, 6, JOY_DOWN)){
    power = BALL_INTAKE_POWER * -1;
  }
  return power;
}
