#include "main.h"
#include "drive.h"

void setDriveMtr(int leftPower, int rightPower){
  leftPower *= 1;
  rightPower *= -1;

  motorSet(DRIVE_LEFT_A_MTR, leftPower);
  motorSet(DRIVE_LEFT_B_MTR, leftPower);
  motorSet(DRIVE_LEFT_C_MTR, leftPower);

  motorSet(DRIVE_RIGHT_A_MTR, rightPower);
  motorSet(DRIVE_RIGHT_B_MTR, rightPower);
  motorSet(DRIVE_RIGHT_C_MTR, rightPower);
}
