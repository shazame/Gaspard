#include <math.h>

#include <terminal.h>

#include "Motors.hpp"

#include "Shoot.hpp"

static double hitRatio = 0;
static double runupRatio = 0;
static int shootEnded = 0;
static double startingAngle = 0;

void shootReset(void)
{
    hitRatio = 0;
    runupRatio = 0;
    shootEnded = 0;
    startingAngle = leftRearLeg.getKneeAngle();
}

static void shootSmooth(RearLeg &rl, double from_a, double to_a, double ratio)
{
    //terminal_io()->println(ratio);

    rl.setKneeAngle(from_a + ratio * (to_a - from_a));
}

void shoot(double dt, double shootRunupSpeed, double shootHitSpeed, double shootAngle)
{
    if (!shootEnded) {
        if (runupRatio < 1) {
            // Step 1: leg going backward to get speed
            //terminal_io()->print("Step1: ");
            runupRatio += (dt * shootRunupSpeed) / (shootAngle - startingAngle);
            shootSmooth(leftRearLeg, startingAngle, shootAngle, runupRatio);
            hitRatio = 0;
        }
        else {
            // Step 2: leg going forward to hit the ball
            if (hitRatio < 1) {
                //terminal_io()->print("Step2: ");
                hitRatio += (dt * shootHitSpeed) / (2*shootAngle);
                shootSmooth(leftRearLeg, shootAngle, -shootAngle, hitRatio);
            }
            else {
                //terminal_io()->println("StepEnd.");
                shootEnded = 1;
            }
        }
    }
}
