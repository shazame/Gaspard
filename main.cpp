#include <cstdlib>
#include <wirish/wirish.h>
#include <servos.h>
#include <terminal.h>
#include <main.h>

#include "Motors.hpp"
#include "BoardLed.hpp"
#include "Walk.hpp"

TERMINAL_PARAMETER_DOUBLE(t, "Temps", 0.0);

#define STATE_INIT 0
#define STATE_WALK 1
#define STATE_RESET 10
TERMINAL_PARAMETER_INT(state, "Robot current state", STATE_INIT);

/**
 * Writing initialization code here
 */
void setup()
{
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
            if (t > 3) {
                t = 0;
                state = STATE_WALK;
            }
            break;
        case STATE_WALK:
            walk(t, 4);
            break;
        case STATE_RESET:
            motors_reset_position();
            state = STATE_INIT;
            break;
        default:
            break;
    }
}

/**
 * Loop method, called everytime
 */
void loop()
{
}
