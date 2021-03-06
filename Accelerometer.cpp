/*
 * @author:
 * 	@lead: Mike Noseworthy
 * 	@awesome: Andrew Horsman
 * @description: Easy accelerometer wrapper class.
 */

// Includes
#include "Headers/WPILibrary.h"

// Accelerometer configuration
static const float SENSITIVITY = 0.3;

/* 
 * Wrapper class for Accelerometer to abstract implicit computing.
 */
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
			
			AccelX.SetZero(0.0);
			AccelY.SetZero(0.0);
		}
		
		float GetXAccel() {
			return AccelX.GetAcceleration();
		}
		
		float GetYAccel() {
			return AccelY.GetAcceleration();
		}
		
};
