#ifndef AUTONOMOUSCODE_H
#define AUTONOMOUSCODE_H
#include "vex.h"

class autonomousCode
{
private:

public:
autonomousCode(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22,vex::motor _RightSpin,vex::motor _LeftSpin);

void LM1stop(vex::motor LM1,vex::motor LM11,vex::motor LM12);
void LM2stop(vex::motor LM2,vex::motor LM21,vex::motor LM22);
void RM1stop(vex::motor RM1,vex::motor RM11,vex::motor RM12);
void RM2stop(vex::motor RM2,vex::motor RM21,vex::motor RM22);

void LM1forward(vex::motor LM1,vex::motor LM11,vex::motor LM12,int speed);
void LM2forward(vex::motor LM2,vex::motor LM21,vex::motor LM22,int speed);
void RM1forward(vex::motor RM1,vex::motor RM11,vex::motor RM12,int speed);
void RM2forward(vex::motor RM2,vex::motor RM21,vex::motor RM22,int speed);

void LM1reverse(vex::motor LM1,vex::motor LM11,vex::motor LM12,int speed);
void LM2reverse(vex::motor LM2,vex::motor LM21,vex::motor LM22,int speed);
void RM1reverse(vex::motor RM1,vex::motor RM11,vex::motor RM12,int speed);
void RM2reverse(vex::motor RM2,vex::motor RM21,vex::motor RM22,int speed);

void LM1spinFwd(vex::motor LM1,vex::motor LM11,vex::motor LM12,int speed);
void LM2spinFwd(vex::motor LM2,vex::motor LM21,vex::motor LM22,int speed);
void RM1spinFwd(vex::motor RM1,vex::motor RM11,vex::motor RM12,int speed);
void RM2spinFwd(vex::motor RM2,vex::motor RM21,vex::motor RM22,int speed);

void LM1spinRev(vex::motor LM1,vex::motor LM11,vex::motor LM12,int speed);
void LM2spinRev(vex::motor LM2,vex::motor LM21,vex::motor LM22,int speed);
void RM1spinRev(vex::motor RM1,vex::motor RM11,vex::motor RM12,int speed);
void RM2spinRev(vex::motor RM2,vex::motor RM21,vex::motor RM22,int speed);

void botForward(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed);

void botBackward(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed);

void botStop(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22);

void strafeLeft(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22,int speed);

void strafeRight(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22,int speed);

void rotateLeftBlue(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed);

void rotateRightRed(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed);
};

#endif