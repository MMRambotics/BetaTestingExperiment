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
		
};
