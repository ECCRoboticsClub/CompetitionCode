#include "vex.h"
#include "autonomousCode.h"

/*THERES FUNCTIONS IN THIS CODE BELOW THAT ARE FOR EITHER RED OR BLUE UNCOMMENT THEM*/
autonomousCode::autonomousCode(vex::motor _LM1,vex::motor _LM11,vex::motor _LM12,
vex::motor _LM2,vex::motor _LM21,vex::motor _LM22,
vex::motor _RM1,vex::motor _RM11,vex::motor _RM12,
vex::motor _RM2,vex::motor _RM21,vex::motor _RM22, vex::motor _RightSpin,vex::motor _LeftSpin)
{
vex::motor LM1 = _LM1;
vex::motor LM11 = _LM11;
vex::motor LM12 = _LM12;
vex::motor LM2 = _LM2;
vex::motor LM21 = _LM21;
vex::motor LM22= _LM22;
vex::motor RM1 = _RM1;
vex::motor RM11 = _RM11;
vex::motor RM12 = _RM12;
vex::motor RM2 = _RM2;
vex::motor RM21 = _RM21;
vex::motor RM22 = _RM22;
vex::motor RightSpin =_RightSpin;
vex::motor LeftSpin= _LeftSpin;

int slow=25;
int fast=100;
int slower=15;

int speed = slow;

//ONE BLOCK
/*
botBackward(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22, speed);

vex::task::sleep( 1700 );

botStop(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22);

botForward(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22, speed);

vex::task::sleep( 1000 );

botStop(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22);

botForward(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22, speed);

vex::task::sleep( 1000 );

botStop(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22);
*/

strafeRight(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22, speed);

vex::task::sleep( 2350 );

botStop(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22);

strafeLeft(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22, speed);

vex::task::sleep( 1275 );

botStop(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22);

speed = slower;
botForward(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22, speed);

//spin intake up
LeftSpin.spin(vex::directionType::rev,fast,vex::velocityUnits::pct);
RightSpin.spin(vex::directionType::rev,fast,vex::velocityUnits::pct);
vex::task::sleep( 4000);

botStop(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22);

LeftSpin.stop();
RightSpin.stop();

LeftSpin.spin(vex::directionType::rev,fast,vex::velocityUnits::pct);
RightSpin.spin(vex::directionType::rev,fast,vex::velocityUnits::pct);
vex::task::sleep( 2000 );
LeftSpin.stop();
RightSpin.stop();

speed = slow;
botBackward(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22, speed);

vex::task::sleep( 3625 );

botStop(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22);

speed = slow;

//UNCOMMENT IF ON RED OR BLUE SIDE
rotateRightRed(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22, speed);

// rotateLeftBlue(LM1,LM11, LM12,
//  LM2, LM21, LM22,
//  RM1, RM11, RM12,
//  RM2, RM21, RM22, speed);

vex::task::sleep( 2300 );

botStop(LM1,LM11, LM12,
 LM2, LM21, LM22,
 RM1, RM11, RM12,
 RM2, RM21, RM22);
}

//STOP
void autonomousCode::LM1stop(vex::motor LM1,vex::motor LM11,vex::motor LM12)
{
  LM1.stop();
  LM11.stop();
  LM12.stop();
}

void autonomousCode::LM2stop(vex::motor LM2,vex::motor LM21,vex::motor LM22)
{
  LM2.stop();
  LM21.stop();
  LM22.stop();
}

void autonomousCode::RM1stop(vex::motor RM1,vex::motor RM11,vex::motor RM12)
{
  RM1.stop();
  RM11.stop();
  RM12.stop();
}

void autonomousCode::RM2stop(vex::motor RM2,vex::motor RM21,vex::motor RM22)
{
  RM2.stop();
  RM21.stop();
  RM22.stop();
  return;
}
//STOP

//FORWARD
void autonomousCode::LM1forward(vex::motor LM1,vex::motor LM11,vex::motor LM12,int speed)
{
  LM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM12.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::LM2forward(vex::motor LM2,vex::motor LM21,vex::motor LM22,int speed)
{
  LM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM22.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::RM1forward(vex::motor RM1,vex::motor RM11,vex::motor RM12,int speed)
{
  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM12.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::RM2forward(vex::motor RM2,vex::motor RM21,vex::motor RM22,int speed)
{
  RM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM22.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}
//FORWARD


//REVERSE
void autonomousCode::LM1reverse(vex::motor LM1,vex::motor LM11,vex::motor LM12, int speed)
{
  LM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM12.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::LM2reverse(vex::motor LM2,vex::motor LM21,vex::motor LM22, int speed)
{
  LM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM22.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::RM1reverse(vex::motor RM1,vex::motor RM11,vex::motor RM12, int speed)
{
  RM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM12.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::RM2reverse(vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed)
{
  RM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM22.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}
// REVERSE


//SPIN FORWARD
void autonomousCode::LM1spinFwd(vex::motor LM1,vex::motor LM11,vex::motor LM12, int speed)
{
  LM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM12.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::LM2spinFwd(vex::motor LM2,vex::motor LM21,vex::motor LM22, int speed)
{
  LM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM22.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::RM1spinFwd(vex::motor RM1,vex::motor RM11,vex::motor RM12, int speed)
{
  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM12.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::RM2spinFwd(vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed)
{
  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM12.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}
// SPIN FORWARD


// SPIN REVERSE
void autonomousCode::LM1spinRev(vex::motor LM1,vex::motor LM11,vex::motor LM12, int speed)
{
  LM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM12.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::LM2spinRev(vex::motor LM2,vex::motor LM21,vex::motor LM22, int speed)
{
  LM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM22.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::RM1spinRev(vex::motor RM1,vex::motor RM11,vex::motor RM12, int speed)
{
  RM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM12.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousCode::RM2spinRev(vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed)
{
  RM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM22.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

//ALL THE MOTORS FORWARD
void autonomousCode::botForward(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed)
{
  LM1spinFwd(LM1,LM11,LM12,speed);
  LM2spinFwd(LM2,LM21,LM22,speed);
  RM1spinFwd(RM1,RM11,RM12,speed);
  RM2spinFwd(RM2,RM21,RM22,speed);
  return;
}

void autonomousCode::botBackward(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed)
{
  LM1spinRev(LM1,LM11,LM12,speed);
  LM2spinRev(LM2,LM21,LM22,speed);
  RM1spinRev(RM1,RM11,RM12,speed);
  RM2spinRev(RM2,RM21,RM22,speed);
  return;
}

void autonomousCode::botStop(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22)
{
  LM1.stop();
  LM11.stop();
  LM12.stop();
  LM2.stop();
  LM21.stop();
  LM22.stop();
  RM1.stop();
  RM11.stop();
  RM12.stop();
  RM2.stop();
  RM21.stop();
  RM22.stop();
  return;
}

void autonomousCode::strafeLeft(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed){

  LM2spinFwd(LM2,LM21,LM22, speed);
  LM1spinRev(LM1,LM11,LM12, speed);
  RM2spinRev(RM2,RM21,RM22,speed);
  RM1spinFwd(RM1,RM11,RM12,speed);
  return;
}

void autonomousCode::strafeRight(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed)
{
  LM2spinRev(LM2,LM21,LM22,speed);
  LM1spinFwd(LM1,LM11,LM12,speed);
  RM2spinFwd(RM2,RM21,RM22,speed);
  RM1spinRev(RM1,RM11,RM12,speed);
  return;
}

void autonomousCode::rotateLeftBlue(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed)
{
  LM2spinRev(LM2,LM21,LM22,speed);
  LM1spinRev(LM1,LM11,LM12,speed);
  RM2spinFwd(RM2,RM21,RM22,speed);
  RM1spinFwd(RM1,RM11,RM12,speed);
  return;
}

void autonomousCode::rotateRightRed(vex::motor LM1,vex::motor LM11,vex::motor LM12,
vex::motor LM2,vex::motor LM21,vex::motor LM22,
vex::motor RM1,vex::motor RM11,vex::motor RM12,
vex::motor RM2,vex::motor RM21,vex::motor RM22, int speed)
{
  LM2spinFwd(LM2,LM21,LM22,speed);
  LM1spinFwd(LM1,LM11,LM12,speed);
  RM2spinRev(RM2,RM21,RM22,speed);
  RM1spinRev(RM1,RM11,RM12,speed);
  return;
}

