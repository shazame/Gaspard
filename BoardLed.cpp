#include <wirish/wirish.h>

#include "BoardLed.hpp"

void boardLedToogle(double t_now)
{
    static double t_old = 0;
    if ( (t_now - t_old) <= BOARD_LED_TOOGLE_PERIOD/2) {
        digitalWrite(BOARD_LED_PIN, HIGH);
    }
    else {
        digitalWrite(BOARD_LED_PIN, LOW);
    }

    if ( (t_now - t_old) > BOARD_LED_TOOGLE_PERIOD || (t_now - t_old) < 0 ) {
        t_old = t_now;
    }
}
