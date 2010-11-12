/*
 * @author:
 * 	@lead: Mike Noseworthy
 * 	@awesome: Andrew Horsman
 * @description: Easy accelerometer wrapper class.
 */

// Includes
#ifndef WPILIB_DEFINE
#define WPILIB_DEFINE
#include "WPILib.h"
#endif

// Accelerometer configuration
static const float SENSITIVITY = 0.3;

class EasyAccel {
	Accelerometer AccelX;
	Accelerometer AccelY;
	
	public:
		EasyAccel(int xPort, int yPort):
			AccelX(xPort),
			AccelY(yPort)
		{
			AccelX.SetSensitivity(SENSITIVITY);
			AccelY.SetSensitivity(SENSITIVITY);
		}
		
		void Zero(){
			AccelX.SetZero(0.0);
		}
		
		float GetXAccel() {
			return AccelX.GetAcceleration();
		}
		
		float GetYAccel() {
			return AccelY.GetAcceleration();
		}
	
};
