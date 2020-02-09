using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftFrontMotor1;
extern motor leftFrontMotor2;
extern motor leftFrontMotor3;
extern motor leftBackMotor1;
extern motor leftBackMotor2;
extern motor leftBackMotor3;
extern motor rightFrontMotor1;
extern motor rightFrontMotor2;
extern motor rightFrontMotor3;
extern motor rightBackMotor1;
extern motor rightBackMotor2;
extern motor rightBackMotor3;
extern motor leftArmMotor;
extern motor rightArmMotor;
extern motor leftIntakeMotor;
extern motor rightIntakeMotor;
extern motor trayPiotMotor;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );