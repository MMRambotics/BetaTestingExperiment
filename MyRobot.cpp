/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Random beta experiments to complete task five.
 */

// Preprocessor configurations
#define DEBUG 

// Includes
#include "Headers/Accelerometer.h"
#include "Headers/Camera.h"
#include "Headers/CameraServo.h"
#include "Headers/Compass.h"
#include "Headers/Gyro.h"
#include "Headers/HelperFunctions.h"
#include "Headers/LightSwitch.h"
#include "Headers/Potentiometer.h"
#include "Headers/Print.h"
#include "Headers/StateMachine.h"
#include "Headers/WPILibrary.h"

// Motor ports configuration.
static const int PAN_MOTOR  = 9;
static const int TILT_MOTOR = 10;

// Camera movement configuration.
static const float CAMERA_PAN_CENTER  = 0.5;
static const float CAMERA_TILT_CENTER = 0.3;
static const float PAN_LEFT_DIRECTION = -1.0; 
static const float TILT_UP_DIRECTION  = 1.0;

// Sensor port configuration.
static const int GYRO_PORT    = 1;
static const int POT_PORT     = 7;
static const int SWITCH_PORT  = 14;
static const int COMPASS_PORT = 1;
static const int ACCELX_PORT = 2;
static const int ACCELY_PORT = 3;

// Joystick port configuration
static const int JOYSTICK_LEFT  = 1;
static const int JOYSTICK_RIGHT = 2;

// Potentiometer voltage configuration.
static const float UPPER_BOUND_VOLTAGE = 4.956;
static const float LOWER_BOUND_VOLTAGE = 0.0005;

// Main class.
class MyRobot : public IterativeRobot {
	
	CameraServo   moveCamera;
	EasyGyro      gyro;
	Print         print;
	EasyCamera    camera;
	Joystick      joystickLeft;
	Joystick      joystickRight;
	LightSwitch   testSwitch;
	Potentiometer pot;
	Helper        helper;
	EasyCompass   compass;
	EasyAccel 	  accel;
	
	public:
		
		MyRobot():
			moveCamera(PAN_MOTOR, TILT_MOTOR, CAMERA_PAN_CENTER, CAMERA_TILT_CENTER, PAN_LEFT_DIRECTION, TILT_UP_DIRECTION),
			gyro(GYRO_PORT),
			print(),
			camera(),
			joystickLeft(JOYSTICK_LEFT),
			joystickRight(JOYSTICK_RIGHT),
			testSwitch(SWITCH_PORT),
			pot(POT_PORT, LOWER_BOUND_VOLTAGE, UPPER_BOUND_VOLTAGE),
			helper(),
			compass(COMPASS_PORT),
			accel(ACCELX_PORT, ACCELY_PORT)
		{
			DisableWatchdog();
		}
		
		~MyRobot() {}
	
		void TeleopInit() {
			DisableWatchdog();
			moveCamera.SetToCenter();
			
			EnableWatchdog();
			FeedWatchdog();
		}
		
		void TeleopPeriodic() {
			FeedWatchdog();
			
			camera.GetImage();
			moveCamera.JoystickControl(joystickLeft);
			
			#ifdef DEBUG
			Debug();
			#endif
		}
		
	private:
		
		void EnableWatchdog() {
			GetWatchdog().SetEnabled(true);
			GetWatchdog().SetExpiration(0.5);
		}
		
		void DisableWatchdog() {
			GetWatchdog().SetEnabled(false);
		}
		
		void FeedWatchdog() {
			GetWatchdog().Feed();
		}
		
		void Debug() {
			print.ClearDisplay();
			
			char gyroHeading[40];
			sprintf(gyroHeading, "Gyro Value: %f", gyro.GetGyroHeading());
			print.PrintText(gyroHeading);
			
			if (testSwitch.IsOn()) {
				print.PrintText("Switch is on!");
			} else {
				print.PrintText("Switch is off!");
			}
			
			char potentiometerVoltage[40];
			sprintf(potentiometerVoltage, "Analog Voltage: %f", pot.GetRawVoltage());
			print.PrintText(potentiometerVoltage);
			
			char potentiometerPosition[40];
			float currentPosition = helper.closeBounds(pot.CalculatePosition());
			sprintf(potentiometerPosition, "Position: %.2f%%", currentPosition);
			print.PrintText(potentiometerPosition);
			
			char compassHeading[40];
			sprintf(compassHeading, "Compass Reading: %f", compass.GetHeading());
			print.PrintText(compassHeading);
		}
	
};

// Start with BetaRobot class, do not change.
START_ROBOT_CLASS(MyRobot);
