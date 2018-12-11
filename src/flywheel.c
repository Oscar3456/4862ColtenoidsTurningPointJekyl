#include "main.h"
#include "flywheel.h"

int fwTime;
int fwPrevTime;
int fwDeltaTime;
int fwTics;
int fwPrevTics;
int fwDeltaTics;
int fwVel;

int fwError;
int fwPrevError;
bool fwFirstCross;
int fwPower;
int fwPowerAtZero;

int fwVelGoal;

Encoder flywheelEnc;

void initFlywheel(){
  flywheelEnc = encoderInit(FW_ENC_TOP, FW_ENC_BOT, false);
}

void setFlywheelMtr(int power){
  motorSet(FLYWHEEL_A_MTR, power);
  motorSet(FLYWHEEL_B_MTR, power);
}

int getFlywheelVelocity(){
  fwTime = RUN_TIME;
  fwDeltaTime = fwTime-fwPrevTime; // calculate time difference
  fwDeltaTime /= 1000;

  fwTics = encoderGet(flywheelEnc);
  fwDeltaTics = fwTics - fwPrevTics;

  fwVel = (fwDeltaTics * 1000.0) / (fwDeltaTime * 60.0); // calculate velocity in tics per second

  fwPrevTime = fwTime;
  fwPrevTics = fwTics;

  return fwVel;
}

void setFlywheelVelocity(int fwGoal, int fwGoalPower){

  fwError = fwGoal - getFlywheelVelocity();

  fwPower += (fwError * FLYWHEEL_KP);

  if ((fwError > 0) != (fwPrevError > 0)){// check if we crossed the zero point
    if (fwFirstCross){
        fwPower = 0.5 * (fwPower + fwGoalPower);
    } else {
      fwPower = 0.5 * (fwPower + fwPowerAtZero);
    }
    fwPowerAtZero = fwPower;
  }

  if(fwPower < 0){ // clip b/c we are only going forewards
    fwPower = 0;
  }

  setFlywheelMtr(fwPower);
}
