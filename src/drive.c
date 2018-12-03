#include "main.h"
#include "drive.h"

Gyro gyro;
Encoder leftEnc;
Encoder rightEnc;
Encoder backEnc;

float angleStart;
float leftStart;
float rightStart;

int rightMtrGoal;
int leftMtrGoal;

void initDrive(){
  gyro = gyroInit(DRIVE_GYRO, 0);
  leftEnc = encoderInit(LEFT_ENC_TOP, LEFT_ENC_TOP, false);
  rightEnc = encoderInit(RIGHT_ENC_TOP, RIGHT_ENC_TOP, false);
  backEnc = encoderInit(BACK_ENC_TOP, BACK_ENC_TOP, false);
}

float getLeftEnc(){
  return encoderGet(leftEnc) * TICKS_TO_INCHES;
}

float getRightEnc(){
  return encoderGet(rightEnc) * TICKS_TO_INCHES;
}

float getEncAngle(){
  return (getLeftEnc() - getRightEnc()) / TRACKING_WIDTH;
}

float degreesToRad(int degrees){
  return degrees * 0.01745329;
}

void startDriveStraight(){
  angleStart = getEncAngle();
  leftStart = getLeftEnc();
  rightStart = getRightEnc();
}

void basicDriveStraight(float distance){
  int distanceErr;
  int angleErr;

  int scaler;

  distanceErr = distance - ((getRightEnc() + getLeftEnc())/2);

  angleErr = angleStart - getEncAngle();

  leftMtrGoal = (distanceErr + (angleErr * LEFT_OFFSET)) * DRIVE_KP;
  rightMtrGoal = (distanceErr + (angleErr * RIGHT_OFFSET)) * DRIVE_KP;

  //scale output
  if(leftMtrGoal >= rightMtrGoal && leftMtrGoal > 127){
      scaler = 127 / leftMtrGoal;
      leftMtrGoal *= scaler;
      rightMtrGoal *= scaler;
  } else if(rightMtrGoal > leftMtrGoal && rightMtrGoal > 127){
    scaler = 127 / rightMtrGoal;
    leftMtrGoal *= scaler;
    rightMtrGoal *= scaler;
  }
}

void setDriveMtr(int leftPower, int rightPower){
  leftPower *= 1;
  rightPower *= -1;

  motorSet(DRIVE_LEFT_A_MTR, leftPower);
  motorSet(DRIVE_LEFT_B_MTR, leftPower);

  motorSet(DRIVE_RIGHT_A_MTR, rightPower);
  motorSet(DRIVE_RIGHT_B_MTR, rightPower);
}

void driveCtrl(){
  setDriveMtr(leftMtrGoal, rightMtrGoal);
}
