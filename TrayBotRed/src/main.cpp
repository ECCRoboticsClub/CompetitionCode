/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include "autonomousCode.h"
#include <algorithm>
#include <cmath>
using namespace vex;

// A global instance of competition
competition Competition;
// define your global instances of motors and other devices here
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton(void) {
// Initializing Robot Configuration. DO NOT REMOVE!
vexcodeInit();
// All activities that occur before the competition starts
// Example: clearing encoders, setting servo positions, ...
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void autonomous(void) {
//speed is controlled inside the autonomous cpp file
autonomousCode newAuton(LM1,LM11,LM12,LM2,LM21,LM22,RM1,RM11,RM12,RM2,RM21,RM22);

}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
// User control code here, inside the loop
while (1) {
// This is the main execution loop for the user control program.
// Each time through the loop your program should update motor + servo
// values based on feedback from the joysticks.
// ........................................................................
// Insert user code here. This is where you use the joystick values to
// update your motors, etc.
// ........................................................................
 // mecanum drive
LM2.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
LM21.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
LM22.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
LM1.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
LM11.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
LM12.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
RM2.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
RM21.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
RM22.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
RM1.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
RM11.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
RM12.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
//2 to 3, 4 to 1, and 1 to 4
int speed = 100;
int slow=75;
//spin control
if(Controller2.ButtonL2.pressing())
{
LeftSpin.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
RightSpin.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
}
else if(Controller2.ButtonL1.pressing())
{
LeftSpin.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
RightSpin.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
}
else
{
LeftSpin.stop(vex::brakeType::brake);
RightSpin.stop(vex::brakeType::brake);
}
//arm control
if(Controller2.ButtonDown.pressing())
{
// LeftArm.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
// RightArm.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
}
else if(Controller2.ButtonUp.pressing())
{
// LeftArm.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
// RightArm.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
}
else
{
// LeftArm.stop(vex::brakeType::hold);
// RightArm.stop(vex::brakeType::hold);
}
//pivot
if(Controller2.ButtonR2.pressing())
{
Pivot.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
}
else if(Controller2.ButtonR1.pressing())
{
Pivot.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
}
else
{
Pivot.stop(vex::brakeType::hold);
}
 //Sleep the task for a short amount of time to prevent wasted resources.
vex::task::sleep(20);
}
vexcodeInit();
}
//
// Main will set up the competition functions and callbacks.
//
int main() {
  vexcodeInit();
// Set up callbacks for autonomous and driver control periods.
Competition.autonomous(autonomous);
Competition.drivercontrol(usercontrol);
// Run the pre-autonomous function.
pre_auton();
}


