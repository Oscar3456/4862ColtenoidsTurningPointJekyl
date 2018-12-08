#include "main.h"
#include "posTracking.h"
#include "math.h"
float globalX;
float globalY;
float globalAngle;

int sign(int num){
  return num / abs(num);
}

float degreeToRad(float degrees){
  return degrees * 0.01745329251994329576923690768489;
}

float radToDegrees(float rad){
  return rad * 57.295779513082320876798154814105;
}

void trackPos(){
  float deltaAngle;
  float averageAngle;
  float localX;
  float localY;
  float deltaD;
  float twoSineAngleOverTwo;

  float prevLeftD;
  float deltaLeftD;
  float prevRightD;
  float deltaRightD;
  float prevBackD;
  float deltaBackD;

  deltaLeftD = getLeftInches() - prevLeftD;
  deltaRightD = getRightInches() - prevRightD;
  deltaBackD = getBackInches() - prevBackD;

  deltaAngle = (deltaLeftD - deltaRightD) / (LEFT_TRACK_OFFSET + RIGHT_TRACK_OFFSET);

  if(deltaAngle == 0){
    twoSineAngleOverTwo = 2 * sin(deltaAngle/2);
    localY = (twoSineAngleOverTwo * ((deltaRightD/deltaAngle) + RIGHT_TRACK_OFFSET));
    localX = (twoSineAngleOverTwo * ((deltaBackD/deltaAngle) + BACK_TRACK_OFFSET));
  }
  else {
    localX = deltaBackD;
    localY = deltaRightD;
  }
  deltaD = sqrt((localY * localY) + (localX * localX));
  averageAngle = globalAngle + (deltaAngle/2);

  globalX += deltaD * cos(averageAngle);
  globalY += deltaD * sin(averageAngle);

  globalAngle += localX;
  if (globalAngle < 0){
    globalAngle += 360;
  } else if (globalAngle > 360){
    globalAngle -= 360;
  }

  lcdClear(uart1);
	lcdPrint(uart1, 1, "%4f", globalX);
	lcdPrint(uart1, 2, "%4f", globalY);
}

void driveToPos(int x, int y, float maxPow){

  /*
  float leftVelGoal;
  float rightVelGoal;
  float outerVel;
  float angleToPoint = atan(y/x) - globalAngle;
  float distanceToPoint = sqrt(((x - globalX) * (x - globalX))  + ((y - globalY) * (y - globalY)) );

  outerVel = distanceToPoint * DRIVE_KP;
  if (outerVel > maxVel){
    outerVel = maxVel;
  }

  float leftEncGoal = (angleToPoint * LEFT_TRACK_OFFSET) + distanceToPoint;
  float rightEncGoal = (-1 * angleToPoint * RIGHT_TRACK_OFFSET) + distanceToPoint;

  if(leftEncGoal > rightEncGoal){
    leftVelGoal = outerVel;
    rightVelGoal = leftVelGoal / (leftEncGoal / rightEncGoal);
  } else {
    rightVelGoal = outerVel;
    leftVelGoal = rightVelGoal / (leftEncGoal / rightEncGoal);
  }*/
}

void turnToPos(float xGoal, float yGoal, int maxPow){
  float angleGoal = atan2(yGoal - globalY, xGoal - globalX);
  float angleErr = angleGoal - globalAngle;

  rightMtrGoal = angleErr * RIGHT_TRACK_OFFSET * DRIVE_KP;
  leftMtrGoal = angleErr * LEFT_TRACK_OFFSET * DRIVE_KP;

  if(abs(rightMtrGoal) > maxPow){
    rightMtrGoal = maxPow * sign(rightMtrGoal);
  }
  if(abs(leftMtrGoal) > maxPow){
    leftMtrGoal = maxPow * sign(leftMtrGoal);
  }
}

void turnToAngle(float angleGoal, int maxPow){
  float angleErr = angleGoal - globalAngle;

  rightMtrGoal = angleErr * RIGHT_TRACK_OFFSET * DRIVE_KP;
  leftMtrGoal = angleErr * LEFT_TRACK_OFFSET * DRIVE_KP;
  
  if(abs(rightMtrGoal) > maxPow){
    rightMtrGoal = maxPow * sign(rightMtrGoal);
  }
  if(abs(leftMtrGoal) > maxPow){
    leftMtrGoal = maxPow * sign(leftMtrGoal);
  }
}
