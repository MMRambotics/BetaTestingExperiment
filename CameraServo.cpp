/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Controls camera servos.
 */

#include "WPILib.h"

class CameraServo {
	
	Servo pan;
	Servo tilt;
	
	public:
	
		CameraServo(int panPort, int tiltPort):
			pan(panPort),
			tilt(tiltPort)
		{}
		

		void SetToCenter() {
			pan.Set(0.5);
			tilt.Set(0.3);
		}
		
};
