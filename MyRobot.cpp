/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Random beta experiments to complete task five.
 */

#include "WPILib.h"
#include "StateMachine.cpp"

class BetaRobot : public IterativeRobot {
	
	Servo pan;
	Servo tilt;
	
	public:
		
		BetaRobot():
			pan(9),
			tilt(10)
		{
			
		}
	
		// Power-on initialization.
		void RobotInit() {
			
		}
		
		// Called when robot gets disabled.
		void DisabledInit() {
			
		}
		
		// Autonomous initialization.
		void AutonomousInit() {
			
		}
		
		// Tele Operated initialization.
		void TeleopInit() {
			
		}
		
		// Called at 100Hz during autonomous.
		void AutonomousPeriodic() {
			
		}
		
		// Called at 100Hz during tele operated.
		void TeleopPeriodic() {
		
		}
	
};

START_ROBOT_CLASS(BetaRobot);
