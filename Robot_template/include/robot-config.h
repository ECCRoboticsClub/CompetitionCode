using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftFrontDrMotor1;
extern motor leftFrontDrMotor2;
extern motor leftFrontDrMotor3;
extern motor leftBackDrMotor1;
extern motor leftBackDrMotor2;
extern motor leftBackDrMotor3;
extern motor rightFrontDrMotor1;
extern motor rightFrontDrMotor2;
extern motor rightFrontDrMotor3;
extern motor rightBackDrMotor1;
extern motor rightBackDrMotor2;
extern motor rightBackDrMotor3;
extern motor leftIntakeMotor;
extern motor rightIntakeMotor;
extern motor trayPivotMotor;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );