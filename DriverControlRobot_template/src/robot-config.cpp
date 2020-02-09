#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftFrontMotor1 = motor(PORT1, ratio18_1, false);
motor leftFrontMotor2 = motor(PORT2, ratio18_1, true);
motor leftFrontMotor3 = motor(PORT3, ratio18_1, false);
motor leftBackMotor1 = motor(PORT4, ratio18_1, false);
motor leftBackMotor2 = motor(PORT5, ratio18_1, true);
motor leftBackMotor3 = motor(PORT6, ratio18_1, false);
motor rightFrontMotor1 = motor(PORT7, ratio18_1, true);
motor rightFrontMotor2 = motor(PORT8, ratio18_1, false);
motor rightFrontMotor3 = motor(PORT9, ratio18_1, true);
motor rightBackMotor1 = motor(PORT10, ratio18_1, true);
motor rightBackMotor2 = motor(PORT11, ratio18_1, false);
motor rightBackMotor3 = motor(PORT12, ratio18_1, true);
motor leftArmMotor = motor(PORT13, ratio18_1, false);
motor rightArmMotor = motor(PORT14, ratio18_1, true);
motor leftIntakeMotor = motor(PORT15, ratio18_1, true);
motor rightIntakeMotor = motor(PORT16, ratio18_1, false);
motor trayPiotMotor = motor(PORT17, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}