#include "RearLeg.hpp"

#include <dxl.h>

void RearLeg::setFootAngle(double a) {
  a = inv ? a : -a;
  dxl_set_position(footIndex, a);
}

void RearLeg::setKneeAngle(double a) {
  a = inv ? -a : a;
  dxl_set_position(kneeIndex, a);
}

double RearLeg::getFootAngle() {
  double mult =  inv ? 1 : -1;
  return mult * dxl_get_position(footIndex);
}

double RearLeg::getKneeAngle() {
  double mult =  inv ? -1 : 1;
  return mult * dxl_get_position(kneeIndex);
}

void RearLeg::setAngles(double * angles)
{
  setFootAngle(angles[0]);
  setKneeAngle(angles[1]);
}
