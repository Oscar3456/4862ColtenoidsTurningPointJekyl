#include "main.h"
#include "sensors.h"

Encoder descorerEnc;

Encoder leftEnc;
Encoder rightEnc;
Encoder backEnc;

void initSensors(){
  analogCalibrate(CATAPULT_POT);
  descorerEnc = encoderInit(DESCORER_ENC_TOP, DESCORER_ENC_BOT, false);
  rightEnc = encoderInit(RIGHT_ENC_TOP, RIGHT_ENC_BOT, false);
  leftEnc = encoderInit(LEFT_ENC_TOP, LEFT_ENC_BOT, false);
  backEnc = encoderInit(BACK_ENC_TOP, BACK_ENC_BOT, false);
}

int getDescorerEnc(){
  return encoderGet(descorerEnc);
}

int getCatapultPot(){
  return analogRead(CATAPULT_POT);
}

int getLeftInches(){
  return encoderGet(leftEnc) * TICKS_TO_2INCH;
}

int getRightInches(){
  return encoderGet(rightEnc) * TICKS_TO_2INCH;
}

int getBackInches(){
  return encoderGet(backEnc) * TICKS_TO_2INCH;
}
