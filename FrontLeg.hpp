#ifndef FRONT_LEG_HPP
#define FRONT_LEG_HPP

class FrontLeg {
private:
  int footIndex;
  int kneeIndex;
  int latIndex;

  bool inv;

public:
  FrontLeg(int footId, int kneeId, int latId, bool inverted) :
      footIndex(footId),
      kneeIndex(kneeId),
      latIndex(latId),
      inv(inverted) {
  }

  void setFootAngle(double a);
  void setKneeAngle(double a);
  void setLatAngle(double a);
  double getFootAngle();
  double getKneeAngle();
  double getLatAngle();
  /* Use an array of size 3 :
   * [ foot, knee, lat ]
   */
  void setAngles(double * a);

  void moveGrounded(double a);
};

#endif//FRONT_LEG_HPP
