/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Controls camera servos.
 */

// Includes
#include "WPILib.h"

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
	
		CameraServo(int panPort, int tiltPort, float panCenter, float tiltCenter, float panLeftDirection, float tiltUpDirection):
			pan(panPort),
			tilt(tiltPort)
		{
			CAMERA_PAN_CENTER  = panCenter;
			CAMERA_TILT_CENTER = tiltCenter;
			
			PAN_LEFT_MULTIPLIER    = panLeftDirection;
			PAN_RIGHT_MULTIPLIER   = panLeftDirection * -1;
			TILT_UP_MULTIPLIER     = tiltUpDirection;
			TILT_DOWN_MULTIPLIER   = tiltUpDirection * -1;
		}
		

		void SetToCenter() {
			pan.Set(CAMERA_PAN_CENTER);
			tilt.Set(CAMERA_TILT_CENTER);
		}
		
		bool PanLeft(int positionOffset = 0.05) {
			float currentPosition = pan.Get();
			if (currentPosition == 0.0)
				return false;
			
			pan.Set(currentPosition + (positionOffset * PAN_LEFT_MULTIPLIER));
			return true;
		}
		
		bool PanRight(int positionOffset = 0.05) {
			float currentPosition = pan.Get();
			if (currentPosition == 1.0)
				return false;
			
			pan.Set(currentPosition + (positionOffset * PAN_RIGHT_MULTIPLIER));
			return true;
		}
		
		bool TiltUp(int positionOffset = 0.05) {
			float currentPosition = tilt.Get();
			if (currentPosition == 0.0)
				return false;
			
			tilt.Set(currentPosition + (positionOffset * TILT_UP_MULTIPLIER));
			return true; 
		}
		
		bool TiltDown(int positionOffset = 0.05) {
			float currentPosition = tilt.Get();
			if (currentPosition == 1.0)
				return true;
			
			tilt.Set(currentPosition + (positionOffset * TILT_DOWN_MULTIPLIER));
			return true;
		}
		
};
