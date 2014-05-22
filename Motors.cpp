#include <dxl.h>

#include "Motors.hpp"

RearLeg rightRearLeg(SERVO_REAR_RIGHT_FOOT,
                     SERVO_REAR_RIGHT_KNEE,
                     0);

RearLeg leftRearLeg(SERVO_REAR_LEFT_FOOT,
                    SERVO_REAR_LEFT_KNEE, 1);

FrontLeg rightFrontLeg(SERVO_FRONT_RIGHT_FOOT,
                       SERVO_FRONT_RIGHT_KNEE,
                       SERVO_FRONT_RIGHT_LAT,
                       1);

FrontLeg leftFrontLeg(SERVO_FRONT_LEFT_FOOT,
                      SERVO_FRONT_LEFT_KNEE,
                      SERVO_FRONT_LEFT_LAT,
                      1);

void motors_init(void)
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
    dxl_set_min_max(6, -110.00, 107.00);
    dxl_set_zero(7, 0.00);
    dxl_set_min_max(7, -90.00, 105.00);
    dxl_set_zero(8, 0.00);
    dxl_set_min_max(8, -97.00, 90.00);
    dxl_set_zero(9, 0.00);
    dxl_set_min_max(9, -110.00, 121.00);
    dxl_set_zero(10, 0.00);
    dxl_set_min_max(10, -103.00, 110.00);
}

void motors_enable_all(void)
{
    for (int i = 1; i <= 10; i++) {
        dxl_enable(i);
    }
}

void motors_disable_all(void)
{
    for (int i = 1; i <= 10; i++) {
        dxl_disable(i);
    }
}

void motors_init_position_all(void)
{
    for (int i = 1; i <= 10; i++) {
        dxl_set_position(i, 0);
    }
}

void motors_reset_position(void)
{
    motors_disable_all();
    motors_init_position_all();
    motors_enable_all();
}
