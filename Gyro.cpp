/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@awesome: Mike Noseworthy
 * @description: Gyro abstraction.
 */

#include "WPILibrary.h"

class EasyGyro {
	
	Gyro gyro;
	
	public:
	
		EasyGyro(int gyroPortNumber): 
			gyro(gyroPortNumber)
		{
			
		}
		
		float GetGyroHeading() {
			return gyro.GetAngle();
		}
	
};
