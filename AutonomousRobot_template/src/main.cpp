/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\bjm32                                            */
/*    Created:      Fri Feb 07 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftFrontMotor1      motor         1
// leftFrontMotor2      motor         2
// leftFrontMotor3      motor         3
// leftBackMotor1       motor         4
// leftBackMotor2       motor         5
// leftBackMotor3       motor         6
// rightFrontMotor1     motor         7
// rightFrontMotor2     motor         8
// rightFrontMotor3     motor         9
// rightBackMotor1      motor         10
// rightBackMotor2      motor         11
// rightBackMotor3      motor         12
// leftArmMotor         motor         13
// rightArmMotor        motor         14
// leftIntakeMotor      motor         15
// rightIntakeMotor     motor         16
// trayPiotMotor        motor         17
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
void leftFrontwheel(int speed, bool wheelDirection);
void leftBackwheel(int speed, bool wheelDirection);
void rightFrontwheel(int speed, bool wheelDirection);
void rightBackwheel(int speed, bool wheelDirection);
void forwardByTime(int speed, int runTime);
void arm(int speed, int runTime);
void reverseByTime(int speed, int runTime);
void leftStrafeByTime(int speed, int runTime);
void rightStrafeByTime(int speed, int runTime);
void rightInplaceTurnByTime(int speed, int runTime);
void leftInplaceTurnByTime(int speed, int runTime);

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  forwardByTime(100, 1000);
  arm(-200, 1000);
  reverseByTime(100, 1000);
  leftStrafeByTime(100, 1000);
  rightStrafeByTime(100, 1000);
  rightInplaceTurnByTime(100, 1000);
  leftInplaceTurnByTime(100, 1000);
}

void leftFrontwheel(int speed, bool wheelDirection) {
  leftFrontMotor1.setVelocity(speed, vex::velocityUnits::pct);
  leftFrontMotor2.setVelocity(speed, vex::velocityUnits::pct);
  leftFrontMotor3.setVelocity(speed, vex::velocityUnits::pct);

  if (wheelDirection == 1) {

    leftFrontMotor1.spin(vex::directionType::fwd);
    leftFrontMotor2.spin(vex::directionType::fwd);
    leftFrontMotor3.spin(vex::directionType::fwd);
  }

  else {

    leftFrontMotor1.spin(vex::directionType::rev);
    leftFrontMotor2.spin(vex::directionType::rev);
    leftFrontMotor3.spin(vex::directionType::rev);
  }
}

void leftBackwheel(int speed, bool wheelDirection) {
  leftBackMotor1.setVelocity(speed, vex::velocityUnits::pct);
  leftBackMotor2.setVelocity(speed, vex::velocityUnits::pct);
  leftBackMotor3.setVelocity(speed, vex::velocityUnits::pct);

  if (wheelDirection == 1) {

    leftBackMotor1.spin(vex::directionType::fwd);
    leftBackMotor2.spin(vex::directionType::fwd);
    leftBackMotor3.spin(vex::directionType::fwd);
  }

  else {

    leftBackMotor1.spin(vex::directionType::rev);
    leftBackMotor2.spin(vex::directionType::rev);
    leftBackMotor3.spin(vex::directionType::rev);
  }
}

void rightFrontwheel(int speed, bool wheelDirection) {
  rightFrontMotor1.setVelocity(speed, vex::velocityUnits::pct);
  rightFrontMotor2.setVelocity(speed, vex::velocityUnits::pct);
  rightFrontMotor3.setVelocity(speed, vex::velocityUnits::pct);

  if (wheelDirection == 1) {

    rightFrontMotor1.spin(vex::directionType::fwd);
    rightFrontMotor2.spin(vex::directionType::fwd);
    rightFrontMotor3.spin(vex::directionType::fwd);
  }

  else {

    rightFrontMotor1.spin(vex::directionType::rev);
    rightFrontMotor2.spin(vex::directionType::rev);
    rightFrontMotor3.spin(vex::directionType::rev);
  }
}

void rightBackwheel(int speed, bool wheelDirection) {
  rightBackMotor1.setVelocity(speed, vex::velocityUnits::pct);
  rightBackMotor2.setVelocity(speed, vex::velocityUnits::pct);
  rightBackMotor3.setVelocity(speed, vex::velocityUnits::pct);

  if (wheelDirection == 1) {

    rightBackMotor1.spin(vex::directionType::fwd);
    rightBackMotor2.spin(vex::directionType::fwd);
    rightBackMotor3.spin(vex::directionType::fwd);
  }

  else {

    rightBackMotor1.spin(vex::directionType::rev);
    rightBackMotor2.spin(vex::directionType::rev);
    rightBackMotor3.spin(vex::directionType::rev);
  }
}

void arm(int speed, int runTime) {
  int speed2;

  if (speed < -100) {
    speed2 = 100;
  }

  else if (speed > -100) {
    speed2 = 100;
  }

  else {
    speed2 = abs(speed);
  }

  rightArmMotor.setVelocity(speed2, vex::velocityUnits::pct);
  leftArmMotor.setVelocity(speed2, vex::velocityUnits::pct);

  if (speed > 0) {

    rightBackMotor1.spin(vex::directionType::fwd);
    rightBackMotor2.spin(vex::directionType::fwd);

  }

  else {

    rightBackMotor1.spin(vex::directionType::rev);
    rightBackMotor2.spin(vex::directionType::rev);
  }
}

void forwardByTime(int speed, int runTime) {

  leftFrontwheel(speed, true);
  leftBackwheel(speed, true);
  rightFrontwheel(speed, true);
  rightBackwheel(speed, true);
  task::sleep(runTime);
}

void reverseByTime(int speed, int runTime) {

  leftFrontwheel(speed, false);
  leftBackwheel(speed, false);
  rightFrontwheel(speed, false);
  rightBackwheel(speed, false);
  task::sleep(runTime);
}

void leftStrafeByTime(int speed, int runTime) {

  leftFrontwheel(speed, false);
  leftBackwheel(speed, true);
  rightFrontwheel(speed, true);
  rightBackwheel(speed, false);
  task::sleep(runTime);
}

void rightStrafeByTime(int speed, int runTime) {

  leftFrontwheel(speed, true);
  leftBackwheel(speed, false);
  rightFrontwheel(speed, false);
  rightBackwheel(speed, true);
  task::sleep(runTime);
}

void rightInplaceTurnByTime(int speed, int runTime) {

  leftFrontwheel(speed, true);
  leftBackwheel(speed, true);
  rightFrontwheel(speed, false);
  rightBackwheel(speed, false);
  task::sleep(runTime);
}

void leftInplaceTurnByTime(int speed, int runTime) {

  leftFrontwheel(speed, false);
  leftBackwheel(speed, false);
  rightFrontwheel(speed, true);
  rightBackwheel(speed, true);
  task::sleep(runTime);
}