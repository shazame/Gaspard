#include <cstdio>
#include <cstdlib>
#include <wirish/wirish.h>
#include <servos.h>
#include <terminal.h>
#include <commands.h>
#include <rc.h>
#include <math.h>
#include <main.h>

#include "Motors.hpp"
#include "BoardLed.hpp"
#include "Walk.hpp"

TERMINAL_PARAMETER_DOUBLE(t, "Temps", 0.0);
TERMINAL_PARAMETER_DOUBLE(walkAngle, "Walking angle", 50);
TERMINAL_PARAMETER_DOUBLE(walkSpeedMax, "Walking speed (in deg/s)", 400);


#define STATE_INIT  1
#define STATE_WALK  2
#define STATE_RESET 10
TERMINAL_PARAMETER_INT(state, "Robot current state", 0);
TERMINAL_PARAMETER_INT(joypad_state, "Joypad state", 0);

#define DEG2RAD(a) ((a) * M_PI / 180.0)

volatile float a1, r1, a2, r2;
volatile float jx1, jy1, jx2, jy2;

/**
 * Writing initialization code here
 */
void setup()
{
    terminal_to_usb();
    motors_init();
    motors_enable_all();
}

/**
 * 50hz function
 */
void tick()
{
    t += 0.02; // 20ms
    boardLedToogle(t);

    switch(state) {
        case STATE_INIT:
            motors_init_position_all();
            walkReset();
            break;
        case STATE_WALK: {
            float walkSpeed = walkSpeedMax * r1 / 10;
            if (jx1 > 0)
                walk(0.02, walkSpeed, walkAngle);
            else if (jx1 < 0)
                walk(0.02, -walkSpeed, walkAngle);
            break;
        }
        case STATE_RESET:
            motors_reset_position();
            state = STATE_INIT;
            break;
        default:
            break;
    }
}

void joypad_flush()
{
    /* Cartesian coordinates */
    jx1 = cos(DEG2RAD(a1))*r1;
    jy1 = sin(DEG2RAD(a1))*r1;
    jx2 = cos(DEG2RAD(a2))*r2;
    jy2 = sin(DEG2RAD(a2))*r2;
}

void joypad_push(unsigned char c)
{
    switch (joypad_state) {
        case 0:
            if (c == 0x55) {
                ++joypad_state;
            }
            if (c == 'B') {
                start_stop();
            }
            if (c == 'C') {
                state = STATE_INIT;
            }
            if (c == 'D') {
                state = STATE_WALK;
            }
            break;
        case 1:
            r1 = c;
            ++joypad_state;
            break;
        case 2:
            a1 = c*10.0;
            ++joypad_state;
            break;
        case 3:
            r2 = c;
            ++joypad_state;
            break;
        case 4:
            a2 = c*10.0;
            joypad_flush();
            joypad_state = 0;
            break;
    }
}

/**
 * Loop method, called everytime
 */
void loop()
{
    while (RC.available()) {
        joypad_push(RC.read());
    }
}
