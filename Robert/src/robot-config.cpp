#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

//VEX PORTS
vex::motor RM1 = vex::motor(vex::PORT10, false);
vex::motor RM11 = vex::motor(vex::PORT9, true);

vex::motor RM2 = vex::motor(vex::PORT20, false);
vex::motor RM21 = vex::motor(vex::PORT19, true);

vex::motor LM1 = vex::motor(vex::PORT15, true);
vex::motor LM11 = vex::motor(vex::PORT16, false);

vex::motor LM2 = vex::motor(vex::PORT13, true);
vex::motor LM21 = vex::motor(vex::PORT12, false);

vex::controller Controller1 = vex::controller();
vex::motor Elevator = vex::motor(vex::PORT5, false);
vex::motor Elevator1 = vex::motor(vex::PORT6, true);
vex::motor Elevator2 = vex::motor(vex::PORT7, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;


void vexcodeInit(void) {
  // Nothing to initialize
}