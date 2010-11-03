/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Controls camera servos.
 */

// Includes
#include "WPILib.h"

// Configuration
static const float CAMERA_PAN_CENTER  = 0.5;
static const float CAMERA_TILT_CENTER = 0.3;

class CameraServo {
	
	Servo pan;
	Servo tilt;
	
	public:
	
		CameraServo(int panPort, int tiltPort):
			pan(panPort),
			tilt(tiltPort)
		{}
		

		void SetToCenter() {
			pan.Set(CAMERA_PAN_CENTER);
			tilt.Set(CAMERA_TILT_CENTER);
		}
		
		bool PanLeft(int positionOffset = 0.05) {
			float currentPosition = pan.Get();
			if (currentPosition == 0.0)
				return false;
			
			pan.Set(currentPosition - positionOffset);
			return true;
		}
		
		bool PanRight(int positionOffset = 0.05) {
			float currentPosition = pan.Get();
			if (currentPosition == 1.0)
				return false;
			
			pan.Set(currentPosition + positionOffset);
			return true;
		}
		
		bool TiltUp(int positionOffset = 0.05) {
			float currentPosition = tilt.Get();
			if (currentPosition == 0.0)
				return false;
			
			tilt.Set(currentPosition - positionOffset);
			return true;
		}
		
		bool TiltDown(int positionOffset = 0.05) {
			float currentPosition = tilt.Get();
			if (currentPosition == 1.0)
				return true;
			
			tilt.Set(currentPosition + positionOffset);
			return true;
		}
		
};
