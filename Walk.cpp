#include <math.h>

#include "Motors.hpp"

#include "Walk.hpp"

void walkMoveSmooth(FrontLeg &fl, RearLeg &bl, double from_a, double to_a, double t, double period)
{
    bl.moveGrounded(from_a + t/period * (to_a - from_a));
    fl.moveGrounded(from_a + t/period * (to_a - from_a));
}

void walk(double t, double period_s, double walk_angle)
{
    double step_period_s = period_s / 8;

    while (t > period_s) {
        t -= period_s;
    }

    // Step 1: 2 legs (1) up and forward
    if (t < step_period_s) {
        walkMoveSmooth(leftFrontLeg, rightRearLeg, 0, walk_angle, t, step_period_s);
    }

    // Step 2: move forward by moving backward the 2 other legs (2), 2 legs (1) get down
    else if (t < 2*step_period_s) {
        walkMoveSmooth(rightFrontLeg, leftRearLeg, 0, -walk_angle, (t - step_period_s), step_period_s);
    }

    // Step 3: 2 legs (1) back to initial position
    else if (t < 3*step_period_s) {
        walkMoveSmooth(leftFrontLeg, rightRearLeg, walk_angle, 0, (t - 2*step_period_s), step_period_s);
    }

    // Step 4: 2 legs (2) back to initial position
    else if (t < 4*step_period_s) {
        walkMoveSmooth(rightFrontLeg, leftRearLeg, -walk_angle, 0, (t - 3*step_period_s), step_period_s);
    }

    // Step 5: 2 legs (2) up and forward
    else if (t < 5*step_period_s) {
        walkMoveSmooth(rightFrontLeg, leftRearLeg, 0, walk_angle, (t - 4*step_period_s), step_period_s);
    }

    // Step 6: 2 legs (1) backward, 2 legs (2) get down
    else if (t < 6*step_period_s) {
        walkMoveSmooth(leftFrontLeg, rightRearLeg, 0, -walk_angle, (t - 5*step_period_s), step_period_s);
    }

    // Step 7: 2 legs (2) back to initial position
    else if (t < 7*step_period_s) {
        walkMoveSmooth(rightFrontLeg, leftRearLeg, walk_angle, 0, (t - 6*step_period_s), step_period_s);
    }

    // Step 8: 2 legs (1) back to initial position
    else {
        walkMoveSmooth(leftFrontLeg, rightRearLeg, -walk_angle, 0, (t - 7*step_period_s), step_period_s);
    }
}
