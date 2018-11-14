#include "main.h"
#include "sensors.h"

Encoder descorerEnc;

void initSensors(){
  analogCalibrate(CATAPULT_POT);
  descorerEnc = encoderInit(DESCORER_ENC_TOP, DESCORER_ENC_BOT, false);
}

int getDescorerEnc(){
  return encoderGet(descorerEnc);
}

int getCatapultPot(){
  return analogRead(CATAPULT_POT);
}
