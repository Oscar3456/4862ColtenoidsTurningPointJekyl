#include "main.h"
#include "posTracking.h"
#include "math.h"

int globalX;
int globalY;
int globalAngle;

void trackPos(){
  int deltaAngle;
  int averageAngle;
  int localX;
  int localY;
  int deltaD;
  int twoSineAngleOverTwo;

  int prevLeftD;
  int deltaLeftD;
  int prevRightD;
  int deltaRightD;
  int prevBackD;
  int deltaBackD;

  while(1){
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
    deltaD = sqrt((localY ^ 2) + (localX ^ 2));
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
		lcdPrint(uart1, 1, "%4d", globalX);
		lcdPrint(uart1, 2, "%4d", globalY);
    wait(20);
  }
}

void driveToPos(int x, int y){
  int angleToPoint = atan(y/x);
  int leftTurn = angleToPoint * LEFT_TRACK_OFFSET;
  int rightTurn = -1 * angleToPoint * LEFT_TRACK_OFFSET;

  int distanceToPoint = sqrt((x ^ 2) + (y ^ 2));

}
