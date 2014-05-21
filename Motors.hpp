#ifndef MOTORS_HPP
#define MOTORS_HPP

#include "RearLeg.hpp"
#include "FrontLeg.hpp"

#define SERVO_FRONT_LEFT_FOOT       2
#define SERVO_FRONT_LEFT_KNEE       4
#define SERVO_FRONT_LEFT_SHOULDER   9

#define SERVO_FRONT_RIGHT_FOOT      3
#define SERVO_FRONT_RIGHT_KNEE      6
#define SERVO_FRONT_RIGHT_SHOULDER  8

#define SERVO_REAR_LEFT_FOOT        1
#define SERVO_REAR_LEFT_KNEE        7

#define SERVO_REAR_RIGHT_FOOT      10
#define SERVO_REAR_RIGHT_KNEE       5

extern RearLeg rightRearLeg;
extern RearLeg leftRearLeg;

extern FrontLeg rightFrontLeg;
extern FrontLeg leftFrontLeg;

void motors_init(void);
void motors_enable_all(void);
void motors_disable_all(void);
void motors_init_position_all(void);
void motors_reset_position(void);

#endif /* MOTORS_HPP */
