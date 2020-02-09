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
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
void leftFrontwheel(int speed);
void leftBackwheel(int speed);
void rightFrontwheel(int speed);
void rightBackwheel(int speed);
void drive(int threshold);
int rightBackwheelvalue(int threshold);
int rightFrontwheelvalue(int threshold);
int leftBackwheelvalue(int threshold);
int leftFrontwheelvalue(int threshold);
int Axis1value(int threshold);
int Axis4value(int threshold);
int Axis3value(int threshold);

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while (true) {
    drive(10);
  }
}

void drive(int threshold) {
  leftFrontwheel(leftFrontwheelvalue(threshold));
  leftBackwheel(leftBackwheelvalue(threshold));
  rightFrontwheel(rightFrontwheelvalue(threshold));
  rightBackwheel(rightBackwheelvalue(threshold));
}

void leftFrontwheel(int speed) {
  leftFrontMotor1.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  leftFrontMotor2.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  leftFrontMotor3.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
}

void leftBackwheel(int speed) {
  leftBackMotor1.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  leftBackMotor2.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  leftBackMotor3.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
}

void rightFrontwheel(int speed) {
  rightFrontMotor1.spin(vex::directionType::fwd, speed,
                        vex::velocityUnits::pct);
  rightFrontMotor2.spin(vex::directionType::fwd, speed,
                        vex::velocityUnits::pct);
  rightFrontMotor3.spin(vex::directionType::fwd, speed,
                        vex::velocityUnits::pct);
}

void rightBackwheel(int speed) {
  rightBackMotor1.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  rightBackMotor2.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  rightBackMotor3.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
}

void arm(int speed2) { // needs work

  rightArmMotor.setVelocity(speed2, vex::velocityUnits::pct);
  leftArmMotor.setVelocity(speed2, vex::velocityUnits::pct);
}

int Axis3value(int threshold) {
  if (abs(Controller1.Axis3.value()) > threshold)
    return Controller1.Axis3.value();
  else
    return 0;
}

int Axis4value(int threshold) {
  if (abs(Controller1.Axis4.value()) > threshold)
    return Controller1.Axis4.value();
  else
    return 0;
}

int Axis1value(int threshold) {
  if (abs(Controller1.Axis1.value()) > threshold)
    return Controller1.Axis1.value();
  else
    return 0;
}

int leftFrontwheelvalue(int threshold) {
  return Axis3value(threshold) + Axis1value(threshold) + Axis4value(threshold);
}
int leftBackwheelvalue(int threshold) {
  return Axis3value(threshold) + Axis1value(threshold) - Axis4value(threshold);
}
int rightFrontwheelvalue(int threshold) {
  return Axis3value(threshold) - Axis1value(threshold) - Axis4value(threshold);
}
int rightBackwheelvalue(int threshold) {
  return Axis3value(threshold) - Axis1value(threshold) + Axis4value(threshold);
}