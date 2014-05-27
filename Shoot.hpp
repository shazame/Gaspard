#ifndef SHOOT_H
#define SHOOT_H

void shootReset(void);
void shoot(double dt, double shootBackSpeed, double shootFrontSpeed, double shootAngle);
int shootIsEnded(void);

#endif /* SHOOT_H */
