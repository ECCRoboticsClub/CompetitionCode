#include "userRobert.h"
userRobert::userRobert(vex::motor _LM1,vex::motor _LM11,
vex::motor _LM2,vex::motor _LM21,
vex::motor _RM1,vex::motor _RM11,
vex::motor _RM2,vex::motor _RM21,
vex::motor _Elevator,vex::motor _Elevator1, vex::motor _Elevator2,
vex::controller _Controller1)
{
vex::motor LM1 = _LM1;
vex::motor LM11 = _LM11;

vex::motor LM2 = _LM2;
vex::motor LM21 = _LM21;

vex::motor RM1 = _RM1;
vex::motor RM11 = _RM11;

vex::motor RM2 = _RM2;
vex::motor RM21 = _RM21;

vex::motor Elevator=_Elevator;
vex::motor Elevator1=_Elevator1;
vex::motor Elevator2=_Elevator2;
vex::controller Controller1= _Controller1;

userMoveFwd(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21);
  int speed = 100;

  // lift
  if (Controller1.ButtonL2.pressing()) {
    userElevatorFwd( Elevator, Elevator1,Elevator2, speed);
  } 
  else if (Controller1.ButtonL1.pressing()) {
    userElevatorRev( Elevator, Elevator1,Elevator2, speed);
  } 
  else {
    userElevatorStop( Elevator, Elevator1,Elevator2);
  }

  //wheel popping
  if (Controller1.ButtonB.pressing()) {
  userWheelPoppingRev(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
  vex::task::sleep( 550 );
  userWheelStop( LM1, LM11,LM2,LM21,RM1, RM11,RM2, RM21);
  userWheelPoppingFwd(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
  vex::task::sleep( 500 );
  userWheelStop( LM1, LM11,LM2,LM21,RM1, RM11,RM2, RM21);
  }

  if (Controller1.ButtonA.pressing()) {
  userWheelPoppingFwd(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
  vex::task::sleep( 550 );
  userWheelStop( LM1, LM11,LM2,LM21,RM1, RM11,RM2, RM21);
  userWheelPoppingRev(LM1,LM11,LM2,LM21,RM1,RM11,RM2,RM21,speed);
  vex::task::sleep( 500 );
  userWheelStop( LM1, LM11,LM2,LM21,RM1, RM11,RM2, RM21);
  }
  
  vex::task::sleep(20); // Sleep the task for a short amount of time to
                        // prevent wasted resources.
}


void userRobert::userWheelFwd(vex::motor LM1,vex::motor LM11,
vex::motor LM2,vex::motor LM21,
vex::motor RM1,vex::motor RM11,
vex::motor RM2,vex::motor RM21, int speed)
 {
  LM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  return;
 }

 void  userRobert::userWheelStop(vex::motor LM1,vex::motor LM11,
                    vex::motor LM2,vex::motor LM21,
                    vex::motor RM1,vex::motor RM11,
                    vex::motor RM2,vex::motor RM21)
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


 void  userRobert::userWheelPoppingRev(vex::motor LM1,vex::motor LM11,
                          vex::motor LM2,vex::motor LM21,
                          vex::motor RM1,vex::motor RM11,
                          vex::motor RM2,vex::motor RM21, int speed)
 {
  LM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);  

  return;
 }

  void  userRobert::userWheelPoppingFwd(vex::motor LM1,vex::motor LM11,
                          vex::motor LM2,vex::motor LM21,
                          vex::motor RM1,vex::motor RM11,
                          vex::motor RM2,vex::motor RM21, int speed)
 {
  LM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM21.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);  

  return;
 }

//ELEVATOR FUNCTIONS
 void  userRobert::userElevatorStop(vex::motor Elevator,vex::motor Elevator1, vex::motor Elevator2)
 {
  Elevator.stop(vex::brakeType::hold);
  Elevator1.stop(vex::brakeType::hold);
  Elevator2.stop(vex::brakeType::hold);
  return;
 }

 void  userRobert::userElevatorRev(vex::motor Elevator,vex::motor Elevator1, vex::motor Elevator2, int speed)
 {
  Elevator.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
  Elevator1.spin(vex::directionType::rev, speed, vex::velocityUnits::pct);
  Elevator2.spin(vex::directionType::rev, speed, vex::velocityUnits::pct); 
  return;
 }

 void userRobert::userElevatorFwd(vex::motor Elevator,vex::motor Elevator1, vex::motor Elevator2, int speed)
 {
  Elevator.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  Elevator1.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  Elevator2.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct); 
  return;
 }
//END OF ELEVATOR FUNCTIONS

 void userRobert::userMoveFwd(vex::motor LM1,vex::motor LM11,
                  vex::motor LM2,vex::motor LM21,
                  vex::motor RM1,vex::motor RM11,
                  vex::motor RM2,vex::motor RM21)
 {
  LM2.spin(vex::directionType::fwd, Controller1.Axis2.value() + Controller1.Axis4.value() - Controller1.Axis1.value(), vex::velocityUnits::pct);
  LM21.spin(vex::directionType::fwd, Controller1.Axis2.value() + Controller1.Axis4.value() - Controller1.Axis1.value(), vex::velocityUnits::pct);
  LM1.spin(vex::directionType::fwd, Controller1.Axis2.value() + Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  LM11.spin(vex::directionType::fwd, Controller1.Axis2.value() + Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  RM2.spin(vex::directionType::fwd, Controller1.Axis2.value() - Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  RM21.spin(vex::directionType::fwd, Controller1.Axis2.value() - Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  RM1.spin(vex::directionType::fwd, Controller1.Axis2.value() - Controller1.Axis4.value() - Controller1.Axis1.value(), vex::velocityUnits::pct);
  RM11.spin(vex::directionType::fwd, Controller1.Axis2.value() - Controller1.Axis4.value() - Controller1.Axis1.value(), vex::velocityUnits::pct);
  return;
 }

