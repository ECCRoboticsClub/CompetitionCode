#include "vex.h"
#include "autonomousRobert.h"
autonomousRobert::autonomousRobert(vex::motor _LM1,vex::motor _LM11,
vex::motor _LM2,vex::motor _LM21,
vex::motor _RM1,vex::motor _RM11,
vex::motor _RM2,vex::motor _RM21)
{
vex::motor LM1 = _LM1; //left motor 1
vex::motor LM11 = _LM11; //left motor 1 of 1

vex::motor LM2 = _LM2; 
vex::motor LM21 = _LM21;

vex::motor RM1 = _RM1; //right motor 1
vex::motor RM11 = _RM11; //right motor 1 of 1

vex::motor RM2 = _RM2;
vex::motor RM21 = _RM21;

int slow=60;
int speed = slow;
int timeRotate = 0;
//RESET POSITION
resetAutonPosition(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21);
//rest of code at the bottom of this cpp file commented out 

//ONLY GETTING ONE BLOCK 

botBackward(LM1,LM11, LM2, LM21, RM1, RM11,  RM2, RM21, speed, timeRotate);
vex::task::sleep( 1700 );
botStop(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21);
botForward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
vex::task::sleep( 1000 );
botStop(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21);
botForward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
vex::task::sleep( 1000 );
botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

//OTHER CODE IF AT OTHER SIDE?
/*
LM2forward(LM2,LM21 ,speed, timeRotate);
LM1reverse(LM1,LM11 ,speed, timeRotate);
RM1reverse(RM1,RM11 ,speed, timeRotate);
RM2forward(RM2,RM21 ,speed, timeRotate);

vex::task::sleep( 1000 );
botStop(LM1,LM11,  
 LM2, LM21,  
 RM1, RM11,  
 RM2, RM21 );
*/
}

void autonomousRobert::resetAutonPosition(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21)
{
  LM1.setPosition(0, degrees);
  LM11.setPosition(0, degrees);
  LM2.setPosition(0, degrees);
  LM21.setPosition(0, degrees);
  RM1.setPosition(0, degrees);
  RM11.setPosition(0, degrees);
  RM2.setPosition(0, degrees);
  RM21.setPosition(0, degrees);

  return;
}

//MOTOR ROTATION

//MOTOR


//STOP
void autonomousRobert::LM1stop(vex::motor LM1,vex::motor LM11 )
{
  LM1.stop();
  LM11.stop();
  return;
}

void autonomousRobert::LM2stop(vex::motor LM2,vex::motor LM21 )
{
  LM2.stop();
  LM21.stop();
  return;
}

void autonomousRobert::RM1stop(vex::motor RM1,vex::motor RM11 )
{
  RM1.stop();
  RM11.stop();
  return;
}

void autonomousRobert::RM2stop(vex::motor RM2,vex::motor RM21 )
{
  RM2.stop();
  RM21.stop();
  return;
}
//STOP

//FORWARD
void autonomousRobert::LM1forward(vex::motor LM1,vex::motor LM11 ,int speed,int timeRotate)
{
  //rotation 
  // LM1.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // LM11.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
 
  
//spins motors
  LM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::LM2forward(vex::motor LM2,vex::motor LM21 ,int speed,int timeRotate)
{
  //ROTATE
  // LM2.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // LM21.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  // //SPIN
  LM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM1forward(vex::motor RM1,vex::motor RM11 ,int speed,int timeRotate)
{
  // RM1.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // RM11.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);  

  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM2forward(vex::motor RM2,vex::motor RM21 ,int speed, int timeRotate )
{

  // RM2.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // RM21.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  RM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}
//FORWARD


//REVERSE
void autonomousRobert::LM1reverse(vex::motor LM1,vex::motor LM11 , int speed, int timeRotate )
{
  // LM1.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // LM11.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  
  LM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::LM2reverse(vex::motor LM2,vex::motor LM21 , int speed, int timeRotate )
{
  // LM2.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // LM21.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  
  LM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM1reverse(vex::motor RM1,vex::motor RM11 , int speed, int timeRotate )
{
  // RM1.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // RM11.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  RM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM2reverse(vex::motor RM2,vex::motor RM21 , int speed, int timeRotate )
{
  // RM2.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // RM21.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);


  RM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}
// REVERSE


//SPIN FORWARD
void autonomousRobert::LM1spinFwd(vex::motor LM1,vex::motor LM11 , int speed, int timeRotate )
{
  // LM1.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // LM11.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  
  LM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::LM2spinFwd(vex::motor LM2,vex::motor LM21 , int speed, int timeRotate )
{
  // LM2.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // LM21.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  LM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM1spinFwd(vex::motor RM1,vex::motor RM11 , int speed, int timeRotate )
{
  // RM1.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // RM11.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM2spinFwd(vex::motor RM2,vex::motor RM21 , int speed, int timeRotate )
{
  // RM2.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // RM21.rotateFor(vex::directionType::fwd,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  RM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
}
// SPIN FORWARD


// SPIN REVERSE
void autonomousRobert::LM1spinRev(vex::motor LM1,vex::motor LM11 , int speed, int timeRotate )
{
  // LM1.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // LM11.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  LM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::LM2spinRev(vex::motor LM2,vex::motor LM21 , int speed, int timeRotate )
{
// LM2.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
// LM2.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  LM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM1spinRev(vex::motor RM1,vex::motor RM11 , int speed, int timeRotate )
{
// RM1.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
// RM11.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  RM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}

void autonomousRobert::RM2spinRev(vex::motor RM2,vex::motor RM21 , int speed, int timeRotate )
{
  // RM2.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);
  // RM21.rotateFor(vex::directionType::rev,timeRotate,vex::timeUnits::sec,speed, vex::velocityUnits::pct);

  RM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  return;
}
//ALL MOTORS ROTATE 


//ALL THE MOTORS FORWARD
void autonomousRobert::botForward(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate )
{
  LM1spinFwd(LM1,LM11,speed, timeRotate);
  LM2spinFwd(LM2,LM21,speed, timeRotate);
  RM1spinFwd(RM1,RM11,speed, timeRotate);
  RM2spinFwd(RM2,RM21,speed, timeRotate);
  return;
}

void autonomousRobert::botBackward(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate )
{
  LM1spinRev(LM1,LM11,speed, timeRotate);
  LM2spinRev(LM2,LM21,speed, timeRotate);
  RM1spinRev(RM1,RM11,speed, timeRotate);
  RM2spinRev(RM2,RM21,speed, timeRotate);
  return;
}

void autonomousRobert::botStop(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 )
{
  LM1.stop();
  LM11.stop();
  LM2.stop();
  LM21.stop();
  RM1.stop();
  RM11.stop();
  RM2.stop();
  RM21.stop();
  return;
}

void autonomousRobert::strafeLeft(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate )
{

  LM2spinFwd(LM2,LM21,speed, timeRotate);
  LM1spinRev(LM1,LM11,speed, timeRotate);
  RM2spinRev(RM2,RM21,speed, timeRotate);
  RM1spinFwd(RM1,RM11,speed, timeRotate);
  return;
}

void autonomousRobert::strafeRight(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate )
{
  LM2spinRev(LM2,LM21,speed, timeRotate);
  LM1spinFwd(LM1,LM11,speed, timeRotate);
  RM2spinFwd(RM2,RM21,speed, timeRotate);
  RM1spinRev(RM1,RM11,speed, timeRotate);
  return;
}

void autonomousRobert::rotateLeftBlue(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate )
{
  LM2spinRev(LM2,LM21,speed, timeRotate);
  LM1spinRev(LM1,LM11,speed, timeRotate);
  RM2spinFwd(RM2,RM21,speed, timeRotate);
  RM1spinFwd(RM1,RM11,speed, timeRotate);
  return;
}

void autonomousRobert::rotateRightRed(vex::motor LM1,vex::motor LM11 ,
vex::motor LM2,vex::motor LM21 ,
vex::motor RM1,vex::motor RM11 ,
vex::motor RM2,vex::motor RM21 , int speed, int timeRotate )
{
  LM2spinFwd(LM2,LM21,speed, timeRotate);
  LM1spinFwd(LM1,LM11,speed, timeRotate);
  RM2spinRev(RM2,RM21,speed, timeRotate);
  RM1spinRev(RM1,RM11,speed, timeRotate);
  return;
}
//ROTATEFOR FUNCTION ONLY WORKS FOR ONE MOTOR AT A TIME
// void vex::motor::rotateFor	(	directionType 	dir,
// double 	time,
// timeUnits 	units,
// double 	velocity,
// velocityUnits 	units_v 
// )		

// void vex::motor::rotateFor	(	double 	time,
// timeUnits 	units,
// double 	velocity,
// velocityUnits 	units_v 
// )	

// void vex::motor::rotateFor	(	directionType 	dir,
// double 	time,
// timeUnits 	units 
// )	


//int timeRotate = 5;  


//MOVING TWO BLOCKS TO THE GOAL

// botBackward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
// vex::task::sleep( 150 );
// botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

// // ~33inches
// strafeRight(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
// //vex::task::sleep( 1600);
// botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);
//vex::task::sleep(400);

// // ~8inches
// botForward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
// vex::task::sleep( 400 );
// botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

// // ~33inches
// timeRotate = 1300;
// strafeLeft(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
// vex::task::sleep( 1300 );
// botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

// //to not make bot touch blocks
// strafeRight(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
// vex::task::sleep( 300);
// botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

// // ~8inches
// botBackward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
// vex::task::sleep( 700 );
// botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

// // // ~12inches
// strafeLeft(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
// vex::task::sleep( 800);
// botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

// // ~48inches
// botForward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
// vex::task::sleep( 1900 );
// botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

// // ~24inches
// //can be any time >500
// botBackward(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed, timeRotate);
// vex::task::sleep( 900);
// botStop(LM1,LM11,LM2, LM21,RM1, RM11,RM2, RM21);

//END OF TWO BLOCK 

