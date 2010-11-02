/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Random beta experiments to complete task five.
 */

// Includes
#include "WPILib.h"
#include "StateMachine.cpp"
#include "CameraServo.cpp"

// Motor ports.
static const int PAN_MOTOR  = 9;
static const int TILT_MOTOR = 10;

// Main class.
class MyRobot : public IterativeRobot {
	
	CameraServo moveCamera;
	
	public:
		
		MyRobot():
			moveCamera(PAN_MOTOR, TILT_MOTOR)
		{}
		
		~MyRobot() {}
	
		// Power-on initialization.
		void RobotInit() {
			FeedWatchdog();
		}
		
		// Called when robot gets disabled.
		void DisabledInit() {
		}
		
		// Autonomous initialization.
		void AutonomousInit() {
			FeedWatchdog();
		}
		
		// Tele Operated initialization.
		void TeleopInit() {
			FeedWatchdog();
			moveCamera.SetToCenter();
		}
		
		// Called at 100Hz during autonomous.
		void AutonomousPeriodic() {
			FeedWatchdog();
		}
		
		// Called at 100Hz during tele operated.
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
