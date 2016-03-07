/* 
 *  AccelStepper Modified to drive more than one 28byj-48 geared step motor at the same time. 
 
AccelStepper stepper(5, pin1, pin2, pin3, pin4);

The first argument '5' indicates that we're using a 28byj-48 geared motor. The rest is just pin numbers. 
The library didn't use number 5 at all so it has its full functionality plus support for 28byj-48 motor.
You can still use all the other types of motors supported by accelstepper library (e.g. 4 for a normal 4 wire step motor, 8 for a halfstepped normal 4 wire motor etc.)
the original library allows adding more than one stepper and supports acceleration. 
When using the ULN2003A driver, for example, use the following defintion after you #include <AccelStepper.h>
AccelStepper stepper1(5, 2, 3, 4, 5);
AccelStepper stepper2(5, 6, 7, 8, 9);

Here is a youtube by kerimil of both 2 28byj-48 steppers in action
http://www.youtube.com/watch?v=Yx8owq4CG-k

 * reference:  
 * pins 2 and 3 need to be swapped, than both FULL4WIRE and HALF4WIRE work as expected
so - define a stepper as follows:
AccelStepper byj(AccelStepper::HALF4WIRE, 8, 10, 9, 11); // byj - pins 2 and 3 swapped !!!
(use HALF4WIRE for half stepping)

arduino pin:         ULN2003A IN pin       out pin      color code on the byj stepper
8                             in4                                D                  blue
9                             in3                               C                  pink
10                            in2                               B                  yellow
11                             in1                               A                  orange
+5v                          vcc                                                   red
*/
#include <AccelStepper.h>
AccelStepper stepper1(5, 2, 3, 4, 5);
 //  The first argument '5' indicates that we're using a 28byj-48 geared motor. The rest is just pin numbers. 
 //   You can still use all the other types of motors supported by accelstepper library (e.g. 4 for a normal 4 wire step motor, 8 for a halfstepped normal 4 wire motor etc.) 
AccelStepper stepper2(5, 6, 7, 8, 9);

void setup()
{  
 stepper1.setMaxSpeed(900.0);     //max speed of the first motor - modify if you want to
 stepper1.setAcceleration(700.0); // rate at which the first motor accelerate -

 stepper2.setMaxSpeed(900.0);
 stepper2.setAcceleration(700.0);
}

void loop()
{    

 if (stepper1.distanceToGo() == 0){
   stepper1.moveTo(random(1500,7000));//just an easy way to get the motors to move to random positions
 } 
 if (stepper2.distanceToGo() == 0){
   stepper2.moveTo(random(1500,7000));
 }
 stepper1.run();
 stepper2.run();

}
