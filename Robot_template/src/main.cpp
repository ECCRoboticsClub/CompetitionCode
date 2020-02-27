// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftFrontDrMotor1    motor         1
// leftFrontDrMotor2    motor         2
// leftFrontDrMotor3    motor         3
// leftBackDrMotor1     motor         4
// leftBackDrMotor2     motor         5
// leftBackDrMotor3     motor         6
// rightFrontDrMotor1   motor         7
// rightFrontDrMotor2   motor         8
// rightFrontDrMotor3   motor         9
// rightBackDrMotor1    motor         10
// rightBackDrMotor2    motor         11
// rightBackDrMotor3    motor         12
// leftIntakeMotor      motor         15
// rightIntakeMotor     motor         16
// trayPivotMotor       motor         17
// Controller1          controller
// frontLimitSwitch     limit         A
// backLimitSwitch      limit         B
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
void intake(int speed);
void driveBase(int threshold);
int rightBackwheelvalue(int threshold);
int rightFrontwheelvalue(int threshold);
int leftBackwheelvalue(int threshold);
int leftFrontwheelvalue(int threshold);
int Axis1value(int threshold);
int Axis2value(int threshold);
int Axis4value(int threshold);
int Axis3value(int threshold);
int speedControl();
void driveStopMotor();
void intakeStopMotor();
int speedValueCheck(int speed);
void forwardByTime(int speed, int runTime);
void reverseByTime(int speed, int runTime);
void leftStrafeByTime(int speed, int runTime);
void rightStrafeByTime(int speed, int runTime);
void rightInplaceTurnByTime(int speed, int runTime);
void leftInplaceTurnByTime(int speed, int runTime);
void driveClearEncoder();
void trayPivotClearEncoder();
void leftFrontwheelRotate(int speed, int rotationNumber);
void leftBackwheelRotate(int speed, int rotationNumber);
void rightFrontwheelRotate(int speed, int rotationNumber);
void rightBackwheelRotate(int speed, int rotationNumber);
void forwardByDistance(int speed, int Distance);
void reverseByDistance(int speed, int Distance);
void leftStrafeByDistance(int speed, int Distance);
void rightStrafeByDistance(int speed, int Distance);
double wheelDiameter(double Wheelsize, std::string Units);
double targetDistance(double targetdistance, double wheelSize,
                      std::string lengthUnits);
void trayPivot(int speed);
void resetTrayPivot();

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  int speedarm = 100, threshold = 10;
  while (true) {
    driveBase(threshold);

    if (Controller1.ButtonLeft.pressing())
      intake(speedarm);
    else if (Controller1.ButtonRight.pressing())
      intake(speedarm);
    else
      intakeStopMotor();
Controller1.ButtonR2.pressed(resetTrayPivot);
    trayPivot(Axis2value(threshold) / speedControl());
  }
}

void driveBase(int threshold) {
  leftFrontwheel(leftFrontwheelvalue(threshold));
  leftBackwheel(leftBackwheelvalue(threshold));
  rightFrontwheel(rightFrontwheelvalue(threshold));
  rightBackwheel(rightBackwheelvalue(threshold));
}

void leftFrontwheel(int speed) {
  leftFrontDrMotor1.spin(vex::directionType::fwd, speed,
                         vex::velocityUnits::pct);
  leftFrontDrMotor2.spin(vex::directionType::fwd, speed,
                         vex::velocityUnits::pct);
  leftFrontDrMotor3.spin(vex::directionType::fwd, speed,
                         vex::velocityUnits::pct);
}

void leftBackwheel(int speed) {
  leftBackDrMotor1.spin(vex::directionType::fwd, speed,
                        vex::velocityUnits::pct);
  leftBackDrMotor2.spin(vex::directionType::fwd, speed,
                        vex::velocityUnits::pct);
  leftBackDrMotor3.spin(vex::directionType::fwd, speed,
                        vex::velocityUnits::pct);
}

void rightFrontwheel(int speed) {
  rightFrontDrMotor1.spin(vex::directionType::fwd, speed,
                          vex::velocityUnits::pct);
  rightFrontDrMotor2.spin(vex::directionType::fwd, speed,
                          vex::velocityUnits::pct);
  rightFrontDrMotor3.spin(vex::directionType::fwd, speed,
                          vex::velocityUnits::pct);
}

void rightBackwheel(int speed) {
  rightBackDrMotor1.spin(vex::directionType::fwd, speed,
                         vex::velocityUnits::pct);
  rightBackDrMotor2.spin(vex::directionType::fwd, speed,
                         vex::velocityUnits::pct);
  rightBackDrMotor3.spin(vex::directionType::fwd, speed,
                         vex::velocityUnits::pct);
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
  if (abs(Controller1.Axis1.value()) > threshold && !Controller1.ButtonL2.pressing())
    return Controller1.Axis1.value();
  else
    return 0;
}

int Axis2value(int threshold) {
  if (abs(Controller1.Axis2.value()) > threshold && Controller1.ButtonL2.pressing())
    return Controller1.Axis2.value();
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
  leftFrontDrMotor1.stop();
  leftFrontDrMotor2.stop();
  leftFrontDrMotor3.stop();
  leftBackDrMotor1.stop();
  leftBackDrMotor2.stop();
  leftBackDrMotor3.stop();
  rightFrontDrMotor1.stop();
  rightFrontDrMotor2.stop();
  rightFrontDrMotor3.stop();
  rightBackDrMotor1.stop();
  rightBackDrMotor2.stop();
  rightBackDrMotor3.stop();
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

  leftFrontDrMotor1.setPosition(0, degrees);
  leftFrontDrMotor2.setPosition(0, degrees);
  leftFrontDrMotor3.setPosition(0, degrees);
  leftBackDrMotor1.setPosition(0, degrees);
  leftBackDrMotor2.setPosition(0, degrees);
  leftBackDrMotor3.setPosition(0, degrees);
  rightFrontDrMotor1.setPosition(0, degrees);
  rightFrontDrMotor2.setPosition(0, degrees);
  rightFrontDrMotor3.setPosition(0, degrees);
  rightBackDrMotor1.setPosition(0, degrees);
  rightBackDrMotor2.setPosition(0, degrees);
  rightBackDrMotor3.setPosition(0, degrees);
}

void trayPivotClearEncoder() { trayPivotMotor.setPosition(0, degrees); }

void leftFrontwheelRotate(int speed, int rotationNumber) {
  leftFrontDrMotor1.setVelocity(speed, pct);
  leftFrontDrMotor2.setVelocity(speed, pct);
  leftFrontDrMotor3.setVelocity(speed, pct);
  leftFrontDrMotor1.spinFor(rotationNumber, degrees);
  leftFrontDrMotor2.spinFor(rotationNumber, degrees);
  leftFrontDrMotor3.spinFor(rotationNumber, degrees);
}

void leftBackwheelRotate(int speed, int rotationNumber) {
  leftBackDrMotor1.setVelocity(speed, pct);
  leftBackDrMotor2.setVelocity(speed, pct);
  leftBackDrMotor3.setVelocity(speed, pct);
  leftBackDrMotor1.spinFor(rotationNumber, degrees);
  leftBackDrMotor2.spinFor(rotationNumber, degrees);
  leftBackDrMotor3.spinFor(rotationNumber, degrees);
}

void rightFrontwheelRotate(int speed, int rotationNumber) {
  rightFrontDrMotor1.setVelocity(speed, pct);
  rightFrontDrMotor2.setVelocity(speed, pct);
  rightFrontDrMotor3.setVelocity(speed, pct);
  rightFrontDrMotor1.spinFor(rotationNumber, degrees);
  rightFrontDrMotor2.spinFor(rotationNumber, degrees);
  rightFrontDrMotor3.spinFor(rotationNumber, degrees);
}

void rightBackwheelRotate(int speed, int rotationNumber) {
  rightBackDrMotor1.setVelocity(speed, pct);
  rightBackDrMotor2.setVelocity(speed, pct);
  rightBackDrMotor3.setVelocity(speed, pct);
  rightBackDrMotor1.spinFor(rotationNumber, degrees);
  rightBackDrMotor2.spinFor(rotationNumber, degrees);
  rightBackDrMotor3.spinFor(rotationNumber, degrees);
}

void forwardByDistance(int speed, double targetdistance, double wheelSize,
                       std::string lengthUnits) {
  driveClearEncoder();
  leftFrontwheelRotate(abs(speedValueCheck(speed)),
                       targetDistance(targetdistance, wheelSize, lengthUnits));
  leftBackwheelRotate(abs(speedValueCheck(speed)),
                      targetDistance(targetdistance, wheelSize, lengthUnits));
  rightFrontwheelRotate(abs(speedValueCheck(speed)),
                        targetDistance(targetdistance, wheelSize, lengthUnits));
  rightBackwheelRotate(abs(speedValueCheck(speed)),
                       targetDistance(targetdistance, wheelSize, lengthUnits));
}

void reverseByDistance(int speed, double targetdistance, double wheelSize,
                       std::string lengthUnits) {
  driveClearEncoder();
  leftFrontwheelRotate(-abs(speedValueCheck(speed)),
                       targetDistance(targetdistance, wheelSize, lengthUnits));
  leftBackwheelRotate(-abs(speedValueCheck(speed)),
                      targetDistance(targetdistance, wheelSize, lengthUnits));
  rightFrontwheelRotate(-abs(speedValueCheck(speed)),
                        targetDistance(targetdistance, wheelSize, lengthUnits));
  rightBackwheelRotate(-abs(speedValueCheck(speed)),
                       targetDistance(targetdistance, wheelSize, lengthUnits));
}

void leftStrafeByDistance(int speed, double targetdistance, double wheelSize,
                          std::string lengthUnits) {
  driveClearEncoder();
  leftFrontwheelRotate(-abs(speedValueCheck(speed)),
                       targetDistance(targetdistance, wheelSize, lengthUnits));
  leftBackwheelRotate(abs(speedValueCheck(speed)),
                      targetDistance(targetdistance, wheelSize, lengthUnits));
  rightFrontwheelRotate(abs(speedValueCheck(speed)),
                        targetDistance(targetdistance, wheelSize, lengthUnits));
  rightBackwheelRotate(-abs(speedValueCheck(speed)),
                       targetDistance(targetdistance, wheelSize, lengthUnits));
}

void rightStrafeByDistance(int speed, double targetdistance, double wheelSize,
                           std::string lengthUnits) {
  driveClearEncoder();
  leftFrontwheelRotate(abs(speedValueCheck(speed)),
                       targetDistance(targetdistance, wheelSize, lengthUnits));
  leftBackwheelRotate(-abs(speedValueCheck(speed)),
                      targetDistance(targetdistance, wheelSize, lengthUnits));
  rightFrontwheelRotate(-abs(speedValueCheck(speed)),
                        targetDistance(targetdistance, wheelSize, lengthUnits));
  rightBackwheelRotate(abs(speedValueCheck(speed)),
                       targetDistance(targetdistance, wheelSize, lengthUnits));
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

double targetDistance(double targetDistance, double wheelSize,
                      std::string lengthUnits) {

  return (360 * targetDistance) / wheelcircumference(wheelSize, lengthUnits);
}

void trayPivot(int speed) {
  if (speed < 0 && backLimitSwitch.value() == 1) {
    trayPivotMotor.stop(hold);
  }

  else if (speed > 0 && frontLimitSwitch.value() == 1) {
    trayPivotMotor.stop(hold);
  }

  else {
    trayPivotMotor.spin(vex::directionType::fwd, speed,
                        vex::velocityUnits::pct);
  }
}

void resetTrayPivot() {
  trayPivot(-100);
}
