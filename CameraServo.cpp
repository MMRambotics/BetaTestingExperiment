/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Controls camera servos.
 */

// Includes
#include "Headers/StateMachine.h"
#include "Headers/WPILibrary.h"

// State Machine constants.
static const int CAMERA_MOVEMENT = 1;
static const int LOCKED   = 1;
static const int UNLOCKED = 2;

// Joystick Buttons
static const int JOYSTICK_TOP_UP    = 3;
static const int JOYSTICK_TOP_DOWN  = 2;
static const int JOYSTICK_TOP_LEFT  = 4;
static const int JOYSTICK_TOP_RIGHT = 5;

// Defaults
static const float DEFAULT_POSITION_INCREMENT = 0.01;

class CameraServo {
	
	Servo pan;
	Servo tilt;
	
	float CAMERA_PAN_CENTER;
	float CAMERA_TILT_CENTER;
	
	float PAN_LEFT_MULTIPLIER;
	float PAN_RIGHT_MULTIPLIER;
	float TILT_UP_MULTIPLIER;
	float TILT_DOWN_MULTIPLIER;
	
	public:
	
		/*
		 * Creates a new CameraServo instance and configures constants.
		 * 
		 * @param int PWM port the pan servo is on.
		 * @param int PWM port the tilt servo is on.
		 * @param float Value between 0.0 and 1.0 where the pan servo is 
		 * centered.
		 * @param float Value between 0.0 and 1.0 where the tilt servo is 
		 * centered.
		 * @param float Specify which value is the left direction (-1.0 or 1.0).
		 * @param float Specify which value is the up direction (-1.0 or 1.0).
		 */
		CameraServo(int panPort, int tiltPort, float panCenter, float tiltCenter, float panLeftDirection, float tiltUpDirection):
			pan(panPort),
			tilt(tiltPort)
		{
			CAMERA_PAN_CENTER  = panCenter;
			CAMERA_TILT_CENTER = tiltCenter;
			
			// Configurable directions.
			PAN_LEFT_MULTIPLIER    = panLeftDirection;
			PAN_RIGHT_MULTIPLIER   = panLeftDirection * -1;
			TILT_UP_MULTIPLIER     = tiltUpDirection;
			TILT_DOWN_MULTIPLIER   = tiltUpDirection * -1;
			
		}
		
		void JoystickControl(Joystick &joystick) {
			if (joystick.GetRawButton(JOYSTICK_TOP_UP)) 
				TiltUp();
			else if (joystick.GetRawButton(JOYSTICK_TOP_DOWN))
				TiltDown();
		
			if (joystick.GetRawButton(JOYSTICK_TOP_LEFT))
				PanLeft();
			else if (joystick.GetRawButton(JOYSTICK_TOP_RIGHT))
				PanRight();
		}
		
		/*
		 * Sets the camera to it's center position.
		 */
		void SetToCenter() {
			pan.Set(CAMERA_PAN_CENTER);
			tilt.Set(CAMERA_TILT_CENTER);
		}
		
		/*
		 * Move the camera to the left.
		 * 
		 * @param float Value between 0.0 and 1.0 of the step the pan motor will 
		 * take to the left.  Default is 0.05.  It would take 20 steps to go 
		 * from 0.0 to 1.0.
		 */
		bool PanLeft(float positionOffset = DEFAULT_POSITION_INCREMENT) {
			float currentPosition = pan.Get();
			if (currentPosition == 0.0)
				return false;
			
			pan.Set(currentPosition + (positionOffset * PAN_LEFT_MULTIPLIER));
			return true;
		}
		
		/*
		 * Move the camera to the right.
		 * 
		 * @param float Value between 0.0 and 1.0 of the step the pan motor will
		 * take to the right.  Default is 0.05.  It would take 20 steps to go
		 * from 0.0 to 1.0.
		 */
		bool PanRight(float positionOffset = DEFAULT_POSITION_INCREMENT) {
			float currentPosition = pan.Get();
			if (currentPosition == 1.0)
				return false;
			
			pan.Set(currentPosition + (positionOffset * PAN_RIGHT_MULTIPLIER));
			return true;
		}
		
		/*
		 * Tilt the camera up.
		 * 
		 * @param float Value between 0.0 to 1.0 of the step the tilt motor will
		 * tilt up by.  Default is 0.05.  It would take 20 steps to go from 0.0
		 * to 1.0.
		 */
		bool TiltUp(float positionOffset = DEFAULT_POSITION_INCREMENT) {
			float currentPosition = tilt.Get();
			if (currentPosition == 0.1)
				return false;
			
			tilt.Set(currentPosition + (positionOffset * TILT_UP_MULTIPLIER));
			return true; 
		}
		
		/*
		 * Tilt the camera down.
		 * 
		 * @param float Value between 0.0 to 1.0 of the step the tilt motor will
		 * tilt down by.  Default is 0.05.  It would take 20 steps to go from 
		 * 0.0 to 1.0.
		 */
		bool TiltDown(float positionOffset = DEFAULT_POSITION_INCREMENT) {
			float currentPosition = tilt.Get();
			if (currentPosition == 0.9)
				return true;
			
			tilt.Set(currentPosition + (positionOffset * TILT_DOWN_MULTIPLIER));
			return true;
		}
		
};
