/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       El Camino College Robotics                                */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Robert        FORKLIFT
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include "autonomousRobert.h"
#include "userRobert.h"
//#include "displayRobert.h"
#include "robot-config.h"
#include <algorithm>
#include <cmath>
using namespace vex;
void controllerPID(double targetVal, double compareVal);
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

autonomousRobert newRobert(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21);
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
  // ........................................................................
//displayRobert robertController(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21, Elevator, Elevator1, Elevator2, Controller1 );
userRobert robertControl(LM1,LM11,LM2,LM21, RM1, RM11, RM2, RM21, Elevator, Elevator1, Elevator2, Controller1 );

}
vexcodeInit();
}
//     wait(20, msec); // Sleep the task for a short amount of time to
//                     // prevent wasted resources.
//   }
// }
//
// Main will set up the competition functions and callbacks.
//
int main() {
// Set up callbacks for autonomous and driver control periods.
vexcodeInit();
Competition.autonomous(autonomous);
Competition.drivercontrol(usercontrol);

//PID STUFF 
/*
double targetVal = LM1.power(vex::powerUnits::watt);
double compareVal = LM11.power(vex::powerUnits::watt);
int powerLevel = 100;
  controllerPID(targetVal, compareVal);
      while(true)
      {
        while(LM1.power(vex::powerUnits::watt) <=500)
        {

// 
//     LM1.efficiency(vex::percentUnits::pct)
// dps pct rpm 
//     LM1.velocity(vex::velocityUnits::rpm) 
// def rev raw
// LM1.rotation(vex::rotationUnits::rev)
// Nm InLb 
// LM1.torque(vex::torqueUnits::Nm)
// 
// LM1.current(vex::currentUnits::amp) 
// 

// LM1.power(vex::powerUnits::watt) 
// pct farenheit 
// LM1.temperature(vex::temperatureUnits::fahrenheit)

        
         int  pidtoggle = 1;
          //motor[righty]=100;
          int powerLevel = 100;
          LM1.setVelocity(powerLevel,rpm);
          LM11.setVelocity(powerLevel,rpm);
          pidtoggle = 0;
        }
        powerLevel = 0;
        LM1.setVelocity(powerLevel,rpm);
        LM11.setVelocity(powerLevel,rpm);
      }
// END PID STUFF 
*/

//TESTING CONTROLLER DISPLAY

// Run the pre-autonomous function.
pre_auton();
// Prevent main from exiting with an infinite loop.
while (true) {
  wait(100, msec);
}
}


void controllerPID(double targetVal, double compareVal)
{
//main goal - current status towards goal
// ex battery at 20% - current status
// main goal - battery at 100%
// error 100-20 =70
//double sensorVal = ;
double error;
double prevError;
//proportional,integral, derivative constant
double kP;
double kI;
double kD;

double integral;
double derivative;
double power;

while(true)
{

//error = targetVal - sensorVal;
integral = integral + error; 
//if (error = 0 || error > targetVal)
// integral =0; //if needs to hold its position, ex arm lifting weight dont use this only for whee
 if ((error = 0) || (error > targetVal))
 {
  integral = 0;
 }
if (error <= -1)
 {
  integral = 0;
 }
//  if (error is outside useful range) 
//  integral = 0;
prevError = 0;
derivative =  error - prevError;
prevError = error;
power = error*kP + integral*kI + derivative*kD;
vex::task::sleep(15);//dT

}
}
