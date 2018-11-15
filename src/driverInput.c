#include "main.h"
#include "driverInput.h"

int getInputLeftDrive(){
  return joystickGetAnalog(1, 2) + joystickGetAnalog(1, 1);
}

int getInputRightDrive(){
  return joystickGetAnalog(1, 2) - joystickGetAnalog(1, 1);
}

int getInputCatapultState(){
  int state; // 2 to fire, 1 to be ready, 0 to be up
  if(joystickGetDigital(1, 5, JOY_UP)){
    state = 1;
  } else if (joystickGetDigital(1, 5, JOY_DOWN)){
    state = 0;
  } else{
    state = 2;
  }
  return state;
}

int getInputDescorer(){
  return joystickGetAnalog(1, 3);
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
