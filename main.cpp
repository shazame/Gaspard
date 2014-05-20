#include <cstdlib>
#include <wirish/wirish.h>
#include <servos.h>
#include <dxl.h>
#include <terminal.h>
#include <main.h>

TERMINAL_PARAMETER_DOUBLE(t, "Temps", 0.0);

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

/**
 * Writing initialization code here
 */
void setup()
{
    // Initialize sheep's servo
    dxl_init();

    // Calibration
    dxl_set_zero(1, 0.00);
    dxl_set_min_max(1, -107.00, 110.00);
    dxl_set_zero(2, 0.00);
    dxl_set_min_max(2, -110.00, 110.00);
    dxl_set_zero(3, 0.00);
    dxl_set_min_max(3, -110.00, 110.00);
    dxl_set_zero(4, 0.00);
    dxl_set_min_max(4, -102.00, 104.00);
    dxl_set_zero(5, 0.00);
    dxl_set_min_max(5, -103.00, 106.00);
    dxl_set_zero(6, 0.00);
    dxl_set_min_max(6, -130.00, 107.00);
    dxl_set_zero(7, 0.00);
    dxl_set_min_max(7, -90.00, 105.00);
    dxl_set_zero(8, 0.00);
    dxl_set_min_max(8, -97.00, 90.00);
    dxl_set_zero(9, 0.00);
    dxl_set_min_max(9, -110.00, 121.00);
    dxl_set_zero(10, 0.00);
    dxl_set_min_max(10, -103.00, 110.00);

    //dxl_enable(1);
    //dxl_enable(2);
    //dxl_enable(3);
    //dxl_enable(4);
    //dxl_enable(5);
    //dxl_enable(6);
    //dxl_enable(7);
    //dxl_enable(8);
    //dxl_enable(9);
    //dxl_enable(10);

    //dxl_set_position(1,  0);
    //dxl_set_position(2,  0);
    //dxl_set_position(3,  0);
    //dxl_set_position(4,  0);
    //dxl_set_position(5,  0);
    //dxl_set_position(6,  0);
    //dxl_set_position(7,  0);
    //dxl_set_position(8,  0);
    //dxl_set_position(9,  0);
    //dxl_set_position(10, 0);
}

#define HALF_PERIOD 0.5

/**
 * 50hz function
 */
void tick()
{
    t += 0.02; // 20ms
	static double t_old = 0;
	if ( (t - t_old) <= HALF_PERIOD) {
		digitalWrite(BOARD_LED_PIN, HIGH);
	}
	else {
		digitalWrite(BOARD_LED_PIN, LOW);
	}

	if ( (t - t_old) > 2*HALF_PERIOD || (t - t_old) < 0 ) {
		t_old = t;
	}
}

/**
 * Loop method, called everytime
 */
void loop()
{
}
