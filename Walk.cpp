#include <math.h>

#include <terminal.h>

#include "Motors.hpp"

#include "Walk.hpp"

static double ratio = 0;

void walkReset(void)
{
    ratio = 0;
}

void walkMoveSmooth(FrontLeg &fl, RearLeg &bl, double from_a, double to_a, double ratio)
{
    terminal_io()->println(ratio);

    bl.moveGrounded(from_a + ratio * (to_a - from_a));
    fl.moveGrounded(from_a + ratio * (to_a - from_a));
}

void walk(double dt, double walkSpeed, double walkAngle)
{
    double step_ratio = 1. / 8;

    ratio += (step_ratio * dt * walkSpeed) / walkAngle;
    if (ratio > 1)
        ratio -= 1;
    else if (ratio < 0)
        ratio += 1;

    // Step 1: 2 legs (1) up and forward
    if (ratio < step_ratio) {
        terminal_io()->print("Step 1:");
        walkMoveSmooth(leftFrontLeg, rightRearLeg, 0, walkAngle, ratio / step_ratio);
    }

    // Step 2: move forward by moving backward the 2 other legs (2), 2 legs (1) get down
    else if (ratio < 2*step_ratio) {
        terminal_io()->print("Step 2:");
        walkMoveSmooth(rightFrontLeg, leftRearLeg, 0, -walkAngle, (ratio - step_ratio) / step_ratio);
    }

    // Step 3: 2 legs (1) back to initial position
    else if (ratio < 3*step_ratio) {
        terminal_io()->print("Step 3:");
        walkMoveSmooth(leftFrontLeg, rightRearLeg, walkAngle, 0, (ratio - 2*step_ratio) / step_ratio);
    }

    // Step 4: 2 legs (2) back to initial position
    else if (ratio < 4*step_ratio) {
        terminal_io()->print("Step 4:");
        walkMoveSmooth(rightFrontLeg, leftRearLeg, -walkAngle, 0, (ratio - 3*step_ratio) / step_ratio);
    }

    // Step 5: 2 legs (2) up and forward
    else if (ratio < 5*step_ratio) {
        terminal_io()->print("Step 5:");
        walkMoveSmooth(rightFrontLeg, leftRearLeg, 0, walkAngle, (ratio - 4*step_ratio) / step_ratio);
    }

    // Step 6: 2 legs (1) backward, 2 legs (2) get down
    else if (ratio < 6*step_ratio) {
        terminal_io()->print("Step 6:");
        walkMoveSmooth(leftFrontLeg, rightRearLeg, 0, -walkAngle, (ratio - 5*step_ratio) / step_ratio);
    }

    // Step 7: 2 legs (2) back to initial position
    else if (ratio < 7*step_ratio) {
        terminal_io()->print("Step 7:");
        walkMoveSmooth(rightFrontLeg, leftRearLeg, walkAngle, 0, (ratio - 6*step_ratio) / step_ratio);
    }

    // Step 8: 2 legs (1) back to initial position
    else {
        terminal_io()->print("Step 8:");
        walkMoveSmooth(leftFrontLeg, rightRearLeg, -walkAngle, 0, (ratio - 7*step_ratio) / step_ratio);
    }
}
