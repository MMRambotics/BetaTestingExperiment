/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Random beta experiments to complete task five.
 */

// Includes
#ifndef WPILIB_DEFINE
#define WPILIB_DEFINE
#include "WPILib.h"
#endif

#ifndef STATE_MACHINE_DEFINE
#define STATE_MACHINE_DEFINE
#include "StateMachine.cpp"
#endif

#ifndef CAMERA_SERVO_DEFINE
#define CAMERA_SERVO_DEFINE
#include "CameraServo.cpp"
#endif

// Motor ports configuration.
static const int PAN_MOTOR  = 9;
static const int TILT_MOTOR = 10;

// Camera movement configuration.
static const float CAMERA_PAN_CENTER  = 0.5;
static const float CAMERA_TILT_CENTER = 0.3;
static const float PAN_LEFT_DIRECTION = 1.0; 
static const float TILT_UP_DIRECTION  = 1.0;

// Main class.
class MyRobot : public IterativeRobot {
	
	CameraServo moveCamera;
	
	public:
		
		MyRobot():
			moveCamera(PAN_MOTOR, TILT_MOTOR, CAMERA_PAN_CENTER, CAMERA_TILT_CENTER, PAN_LEFT_DIRECTION, TILT_UP_DIRECTION)
		{}
		
		~MyRobot() {}
	
		void TeleopInit() {
			EnableWatchdog();
			FeedWatchdog();
			moveCamera.SetToCenter();
		}
		
		void TeleopPeriodic() {
			FeedWatchdog();
		}
		
	private:
		
		void EnableWatchdog() {
			GetWatchdog().SetEnabled(true);
		}
		
		void DisableWatchdog() {
			GetWatchdog().SetEnabled(false);
		}
		
		void FeedWatchdog() {
			GetWatchdog().Feed();
		}
	
};

// Start with BetaRobot class, do not change.
START_ROBOT_CLASS(MyRobot);
