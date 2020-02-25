#ifndef AUTONOMOUSROBERT_H
#define AUTONOMOUSROBERT_H
#include "vex.h"

class autonomousRobert
{
private:

public:

autonomousRobert(vex::motor LM1,vex::motor LM11,
vex::motor LM2,vex::motor LM21,
vex::motor RM1,vex::motor RM11,
vex::motor RM2,vex::motor RM21);

void resetAutonPosition(vex::motor LM1,vex::motor LM11,
vex::motor LM2,vex::motor LM21,
vex::motor RM1,vex::motor RM11,
vex::motor RM2,vex::motor RM21);

void LM1stop(vex::motor LM1,vex::motor LM11);
void LM2stop(vex::motor LM2,vex::motor LM21);
void RM1stop(vex::motor RM1,vex::motor RM11);
void RM2stop(vex::motor RM2,vex::motor RM21);

void LM1forward(vex::motor LM1,vex::motor LM11 ,int speed, int timeRotate);
void LM2forward(vex::motor LM2,vex::motor LM21 ,int speed, int timeRotate);
void RM1forward(vex::motor RM1,vex::motor RM11 ,int speed, int timeRotate);
void RM2forward(vex::motor RM2,vex::motor RM21 ,int speed, int timeRotate);

void LM1reverse(vex::motor LM1,vex::motor LM11 ,int speed, int timeRotate);
void LM2reverse(vex::motor LM2,vex::motor LM21 ,int speed, int timeRotate);
void RM1reverse(vex::motor RM1,vex::motor RM11 ,int speed, int timeRotate);
void RM2reverse(vex::motor RM2,vex::motor RM21 ,int speed, int timeRotate);

void LM1spinFwd(vex::motor LM1,vex::motor LM11 ,int speed, int timeRotate);
void LM2spinFwd(vex::motor LM2,vex::motor LM21 ,int speed, int timeRotate);
void RM1spinFwd(vex::motor RM1,vex::motor RM11 ,int speed, int timeRotate);
void RM2spinFwd(vex::motor RM2,vex::motor RM21 ,int speed, int timeRotate);

void LM1spinRev(vex::motor LM1,vex::motor LM11 ,int speed, int timeRotate);
void LM2spinRev(vex::motor LM2,vex::motor LM21 ,int speed, int timeRotate);
void RM1spinRev(vex::motor RM1,vex::motor RM11 ,int speed, int timeRotate);
void RM2spinRev(vex::motor RM2,vex::motor RM21 ,int speed, int timeRotate);

void botForward(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21  ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate);

void botBackward(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21  ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate);

void botStop(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21  ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 );

void strafeLeft(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21  ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 ,int speed, int timeRotate);

void strafeRight(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21  ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 ,int speed, int timeRotate);

void rotateLeftBlue(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21  ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate);

void rotateRightRed(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21  ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate);
};

#endif