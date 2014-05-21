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

void FrontLeg::setLatAngle(double a) {
  a = inv ? -a : a;
  dxl_set_position(latIndex, a);
}

double FrontLeg::getFootAngle() {
  double mult =  inv ? 1 : -1;
  return mult * dxl_get_position(footIndex);
}

double FrontLeg::getKneeAngle() {
  double mult =  inv ? -1 : 1;
  return mult * dxl_get_position(kneeIndex);
}

double FrontLeg::getLatAngle() {
  double mult =  inv ? -1 : 1;
  return mult * dxl_get_position(latIndex);
}

void FrontLeg::setAngles(double * angles)
{
  setFootAngle(angles[0]);
  setKneeAngle(angles[1]);
  setLatAngle(angles[2]);
}
}
