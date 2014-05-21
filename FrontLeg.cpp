#include "FrontLeg.hpp"

#include <dxl.h>

void FrontLeg::setFootAngle(double a) {
  a = inv ? a : -a;
  dxl_set_position(footIndex, a);
}

void FrontLeg::setKneeAngle(double a) {
  a = inv ? -a : a;
  dxl_set_position(kneeIndex, a);
}

void FrontLeg::setShoulderAngle(double a) {
  a = inv ? -a : a;
  dxl_set_position(shoulderIndex, a);
}

double FrontLeg::getFootAngle() {
  double mult =  inv ? 1 : -1;
  return mult * dxl_get_position(footIndex);
}

double FrontLeg::getKneeAngle() {
  double mult =  inv ? -1 : 1;
  return mult * dxl_get_position(kneeIndex);
}

double FrontLeg::getShoulderAngle() {
  double mult =  inv ? -1 : 1;
  return mult * dxl_get_position(shoulderIndex);
}

void FrontLeg::setAngles(double * angles)
{
  setFootAngle(angles[0]);
  setKneeAngle(angles[1]);
  setShoulderAngle(angles[2]);
}
