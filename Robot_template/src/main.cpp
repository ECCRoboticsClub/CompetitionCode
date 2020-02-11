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
// trayPivotMotor       motor         17
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <string>
using namespace vex;

double wheelSize = 4;
std::string lengthUnits = "inches";

void leftFrontwheel(int speed);
void leftBackwheel(int speed);
void rightFrontwheel(int speed);
void rightBackwheel(int speed);
void arm(int speed);
void intake(int speed);
void drive(int threshold);
int rightBackwheelvalue(int threshold);
int rightFrontwheelvalue(int threshold);
int leftBackwheelvalue(int threshold);
int leftFrontwheelvalue(int threshold);
int Axis1value(int threshold);
int Axis4value(int threshold);
int Axis3value(int threshold);
int speedControl();
void driveStopMotor();
void armStopMotor();
void intakeStopMotor();
int speedValueCheck(int speed);
void arm(int speed, int runTime);
void forwardByTime(int speed, int runTime);
void reverseByTime(int speed, int runTime);
void leftStrafeByTime(int speed, int runTime);
void rightStrafeByTime(int speed, int runTime);
void rightInplaceTurnByTime(int speed, int runTime);
void leftInplaceTurnByTime(int speed, int runTime);
void driveClearEncoder();
void armClearEncoder();
void trayPivotClearEncoder();
void leftFrontwheelRotate(int speed, int rotationNumber);
void leftBackwheelRotate(int speed, int rotationNumber);
void rightFrontwheelRotate(int speed, int rotationNumber);
void rightBackwheelRotate(int speed, int rotationNumber);
void armRotate(int speed, int rotationNumber);
void forwardByDistance(int speed, int Distance);
void reverseByDistance(int speed, int Distance);
void leftStrafeByDistance(int speed, int Distance);
void rightStrafeByDistance(int speed, int Distance);
double wheelDiameter(double Wheelsize, std::string Units);
double targetDistance(double Wheeldiameter);

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  int speedarm = 100;
  while (true) {
    drive(10);

    if (Controller1.ButtonUp.pressing())
    arm(speedarm / speedControl());
  else if (Controller1.ButtonDown.pressing())
    arm(speedarm / speedControl());
  else
    armStopMotor();

if (Controller1.ButtonLeft.pressing())
    intake(speedarm / speedControl());
  else if (Controller1.ButtonRight.pressing())
    intake(speedarm / speedControl());
  else
    intakeStopMotor();
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

void arm(int speed) { // needs work

  rightArmMotor.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  leftArmMotor.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
}

void intake(int speed) { // needs work

  leftIntakeMotor.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  rightIntakeMotor.spin(vex::directionType::fwd, speed,
                        vex::velocityUnits::pct);
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

int speedControl() {
  if (Controller1.ButtonR1.pressing())
    return 1;
  else if (Controller1.ButtonL1.pressing())
    return 4;
  else
    return 2;
}

void driveStopMotor() {
  leftFrontMotor1.stop();
  leftFrontMotor2.stop();
  leftFrontMotor3.stop();
  leftBackMotor1.stop();
  leftBackMotor2.stop();
  leftBackMotor3.stop();
  rightFrontMotor1.stop();
  rightFrontMotor2.stop();
  rightFrontMotor3.stop();
  rightBackMotor1.stop();
  rightBackMotor2.stop();
  rightBackMotor3.stop();
}

void armStopMotor() {
  leftArmMotor.stop();
  rightArmMotor.stop();
}

void intakeStopMotor() {
  leftIntakeMotor.stop();
  rightIntakeMotor.stop();
}

int speedValueCheck(int speed) {

  if (speed < -100) {
    return -100;
  }

  else if (speed > 100) {
    return 100;
  }

  else {
    return speed;
  }
}

void forwardByTime(int speed, int runTime) {

  leftFrontwheel(abs(speedValueCheck(speed)));
  leftBackwheel(abs(speedValueCheck(speed)));
  rightFrontwheel(abs(speedValueCheck(speed)));
  rightBackwheel(abs(speedValueCheck(speed)));
  wait(runTime, msec);
}

void reverseByTime(int speed, int runTime) {

  leftFrontwheel(-abs(speedValueCheck(speed)));
  leftBackwheel(-abs(speedValueCheck(speed)));
  rightFrontwheel(-abs(speedValueCheck(speed)));
  rightBackwheel(-abs(speedValueCheck(speed)));
  wait(runTime, msec);
}

void leftStrafeByTime(int speed, int runTime) {

  leftFrontwheel(-abs(speedValueCheck(speed)));
  leftBackwheel(abs(speedValueCheck(speed)));
  rightFrontwheel(abs(speedValueCheck(speed)));
  rightBackwheel(-abs(speedValueCheck(speed)));
  wait(runTime, msec);
}

void rightStrafeByTime(int speed, int runTime) {

  leftFrontwheel(abs(speedValueCheck(speed)));
  leftBackwheel(-abs(speedValueCheck(speed)));
  rightFrontwheel(-abs(speedValueCheck(speed)));
  rightBackwheel(abs(speedValueCheck(speed)));
  wait(runTime, msec);
}

void rightInplaceTurnByTime(int speed, int runTime) {

  leftFrontwheel(abs(speedValueCheck(speed)));
  leftBackwheel(abs(speedValueCheck(speed)));
  rightFrontwheel(-abs(speedValueCheck(speed)));
  rightBackwheel(-abs(speedValueCheck(speed)));
  wait(runTime, msec);
}

void leftInplaceTurnByTime(int speed, int runTime) {

  leftFrontwheel(-abs(speedValueCheck(speed)));
  leftBackwheel(-abs(speedValueCheck(speed)));
  rightFrontwheel(abs(speedValueCheck(speed)));
  rightBackwheel(abs(speedValueCheck(speed)));
  wait(runTime, msec);
}

void driveClearEncoder() {

  leftFrontMotor1.setPosition(0, degrees);
  leftFrontMotor2.setPosition(0, degrees);
  leftFrontMotor3.setPosition(0, degrees);
  leftBackMotor1.setPosition(0, degrees);
  leftBackMotor2.setPosition(0, degrees);
  leftBackMotor3.setPosition(0, degrees);
  rightFrontMotor1.setPosition(0, degrees);
  rightFrontMotor2.setPosition(0, degrees);
  rightFrontMotor3.setPosition(0, degrees);
  rightBackMotor1.setPosition(0, degrees);
  rightBackMotor2.setPosition(0, degrees);
  rightBackMotor3.setPosition(0, degrees);
}

void armClearEncoder() {
  rightArmMotor.setPosition(0, degrees);
  leftArmMotor.setPosition(0, degrees);
}

void trayPivotClearEncoder() { trayPivotMotor.setPosition(0, degrees); }

void leftFrontwheelRotate(int speed, int rotationNumber) {
  leftFrontMotor1.setVelocity(speed, pct);
  leftFrontMotor2.setVelocity(speed, pct);
  leftFrontMotor3.setVelocity(speed, pct);
  leftFrontMotor1.spinFor(rotationNumber, degrees);
  leftFrontMotor2.spinFor(rotationNumber, degrees);
  leftFrontMotor3.spinFor(rotationNumber, degrees);
}

void leftBackwheelRotate(int speed, int rotationNumber) {
  leftBackMotor1.setVelocity(speed, pct);
  leftBackMotor2.setVelocity(speed, pct);
  leftBackMotor3.setVelocity(speed, pct);
  leftBackMotor1.spinFor(rotationNumber, degrees);
  leftBackMotor2.spinFor(rotationNumber, degrees);
  leftBackMotor3.spinFor(rotationNumber, degrees);
}

void rightFrontwheelRotate(int speed, int rotationNumber) {
  rightFrontMotor1.setVelocity(speed, pct);
  rightFrontMotor2.setVelocity(speed, pct);
  rightFrontMotor3.setVelocity(speed, pct);
  rightFrontMotor1.spinFor(rotationNumber, degrees);
  rightFrontMotor2.spinFor(rotationNumber, degrees);
  rightFrontMotor3.spinFor(rotationNumber, degrees);
}

void rightBackwheelRotate(int speed, int rotationNumber) {
  rightBackMotor1.setVelocity(speed, pct);
  rightBackMotor2.setVelocity(speed, pct);
  rightBackMotor3.setVelocity(speed, pct);
  rightBackMotor1.spinFor(rotationNumber, degrees);
  rightBackMotor2.spinFor(rotationNumber, degrees);
  rightBackMotor3.spinFor(rotationNumber, degrees);
}

void armRotate(int speed, int rotationNumber) {

  rightArmMotor.rotateTo(rotationNumber, degrees);
  leftArmMotor.rotateTo(rotationNumber, degrees);
  rightArmMotor.setVelocity(speed, pct);
  leftArmMotor.setVelocity(speed, pct);
}

void forwardByDistance(int speed, int Distance) {
  driveClearEncoder();
  leftFrontwheelRotate(abs(speedValueCheck(speed)), targetDistance(Distance));
  leftBackwheelRotate(abs(speedValueCheck(speed)), targetDistance(Distance));
  rightFrontwheelRotate(abs(speedValueCheck(speed)), targetDistance(Distance));
  rightBackwheelRotate(abs(speedValueCheck(speed)), targetDistance(Distance));
}

void reverseByDistance(int speed, int Distance) {
  driveClearEncoder();
  leftFrontwheelRotate(-abs(speedValueCheck(speed)), targetDistance(Distance));
  leftBackwheelRotate(-abs(speedValueCheck(speed)), targetDistance(Distance));
  rightFrontwheelRotate(-abs(speedValueCheck(speed)), targetDistance(Distance));
  rightBackwheelRotate(-abs(speedValueCheck(speed)), targetDistance(Distance));
}

void leftStrafeByDistance(int speed, int Distance) {
  driveClearEncoder();
  leftFrontwheelRotate(-abs(speedValueCheck(speed)), targetDistance(Distance));
  leftBackwheelRotate(abs(speedValueCheck(speed)), targetDistance(Distance));
  rightFrontwheelRotate(abs(speedValueCheck(speed)), targetDistance(Distance));
  rightBackwheelRotate(-abs(speedValueCheck(speed)), targetDistance(Distance));
}

void rightStrafeByDistance(int speed, int Distance) {
  driveClearEncoder();
  leftFrontwheelRotate(abs(speedValueCheck(speed)), targetDistance(Distance));
  leftBackwheelRotate(-abs(speedValueCheck(speed)), targetDistance(Distance));
  rightFrontwheelRotate(-abs(speedValueCheck(speed)), targetDistance(Distance));
  rightBackwheelRotate(abs(speedValueCheck(speed)), targetDistance(Distance));
}

double wheelcircumference(double Wheelsize, std::string lengthUnits) {
  double Wheelsize2;
  if (lengthUnits == "cm" || "centimeter") {
    Wheelsize2 = Wheelsize * 0.393701;
  } else if (lengthUnits == "mm" || "centimeter") {
    Wheelsize2 = Wheelsize * 0.0393701;
  } else if (lengthUnits == "in" || "inch") {
    Wheelsize2 = Wheelsize;
  }
  return Wheelsize2 * 3.14159265359;
}

double targetDistance(double targetDistance) {

  return (360 * targetDistance) / wheelcircumference(wheelSize, lengthUnits);
}
