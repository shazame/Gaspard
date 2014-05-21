#ifndef FRONT_LEG_HPP
#define FRONT_LEG_HPP

class FrontLeg {
private:
  int footIndex;
  int kneeIndex;
  int shoulderIndex;

  bool inv;

public:
  FrontLeg(int footId, int kneeId, int shoulderId, bool inverted) :
      footIndex(footId),
      kneeIndex(kneeId),
      shoulderIndex(shoulderId),
      inv(inverted) {
  }

  void setFootAngle(double a);
  void setKneeAngle(double a);
  void setShoulderAngle(double a);
  double getFootAngle();
  double getKneeAngle();
  double getShoulderAngle();
  /* Use an array of size 3 :
   * [ foot, knee, shoulder ]
   */
  void setAngles(double * a);
};

#endif//FRONT_LEG_HPP
