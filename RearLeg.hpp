#ifndef REAR_LEG_HPP
#define REAR_LEG_HPP

class RearLeg {
private:
  int footIndex;
  int kneeIndex;

  bool inv;

public:
  RearLeg(int foot_id, int knee_id, bool inverted) :
      footIndex(foot_id),
      kneeIndex(knee_id),
      inv(inverted) {
  }

  void setFootAngle(double a);
  void setKneeAngle(double a);
  double getFootAngle();
  double getKneeAngle();
  /* Use an array of size 2 :
   * [ foot, knee ]
   */
  void setAngles(double * a);

  void moveGrounded(double a);
};

#endif//REAR_LEG_HPP
