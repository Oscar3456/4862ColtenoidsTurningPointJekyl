#ifndef _POSTRACKING_H_
#define _POSTRACKING_H_

void trackPos();

int degreeToRad(int degrees){
  return degrees * 0.01745329251994329576923690768489;
}

void driveToPos(int x, int y);

#endif // _POSTRACKING_H_
