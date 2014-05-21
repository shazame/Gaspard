#include <math.h>

#include "Motors.hpp"

#include "Walk.hpp"

void walk(double t, double period_s)
{
    rightRearLeg.setKneeAngle(50 * sin(t * (2*M_PI) / period_s));
    leftFrontLeg.setKneeAngle(50 * sin(t * (2*M_PI) / period_s));

    leftRearLeg.setKneeAngle  (50 * sin((t+period_s/2) * (2*M_PI) / period_s));
    rightFrontLeg.setKneeAngle(50 * sin((t+period_s/2) * (2*M_PI) / period_s));
}
