#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

//VEX PORTS
vex::motor LM1 = vex::motor(vex::PORT20,false);
vex::motor LM11 = vex::motor(vex::PORT19,true);
vex::motor LM12 = vex::motor(vex::PORT18,true);
vex::motor LM2 = vex::motor(vex::PORT10,false);
vex::motor LM21 = vex::motor(vex::PORT9,true);
vex::motor LM22 = vex::motor(vex::PORT8,true);
vex::motor RM1 = vex::motor(vex::PORT11,true);
vex::motor RM11 = vex::motor(vex::PORT12,false);
vex::motor RM12 = vex::motor(vex::PORT4,false);
vex::motor RM2 = vex::motor(vex::PORT1,true);
vex::motor RM21 = vex::motor(vex::PORT2,false);
vex::motor RM22 = vex::motor(vex::PORT3,false);
vex::controller Controller2 = vex::controller();
vex::motor LeftArm = vex::motor(vex::PORT16,false);//19 to 16
vex::motor RightArm = vex::motor(vex::PORT14,true);//moved from 12 to 14
vex::motor LeftSpin = vex::motor(vex::PORT6,true);// 9 to 6
vex::motor RightSpin = vex::motor(vex::PORT5,false);//moved from 2 to 5
vex::motor Pivot = vex::motor(vex::PORT15,true);  //keep

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

void vexcodeInit(void) {
  // Nothing to initialize
}
