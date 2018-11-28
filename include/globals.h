#ifndef _GLOBAL_H_
#define _GLOBAL_H_

//DEFINE MOTORS:
#define BALL_INTAKE_MTR 1

#define DRIVE_LEFT_A_MTR 2

#define CATAPULT_A_MTR 3      // Power Expander A
#define DRIVE_LEFT_B_MTR 4    // Power Expander B

#define DRIVE_LEFT_C_MTR 5
#define DRIVE_RIGHT_C_MTR 6

#define DRIVE_RIGHT_B_MTR 7 // Power Expander C
#define CATAPULT_B_MTR 8   // Power Expander D

#define DRIVE_RIGHT_A_MTR 9

#define DESCORER_MTR 10

//DEFINE ANALOG SENSORS

#define CATAPULT_POT 1

//DEFINE DIGITAL SENSORS
#define DESCORER_ENC_TOP 1
#define DESCORER_ENC_BOT 2

#define DESCORER_POWER 110

#define DESCORER_MAX 200
#define DESCORER_MIN 200

#define DESCORER_KP 1


#define CATAPULT_UP_POS 5
#define CATAPULT_DOWN_POS -1150
#define CATAPULT_FIRE_POS  -1230

#define CATAPULT_INTEGRAL_RANGE 400
#define CATAPULT_KP 0.2
#define CATAPULT_KI 0.001


#define BALL_INTAKE_POWER 110

#endif // _GLOBAL_H_
