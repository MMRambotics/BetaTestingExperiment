/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@awesome: Mike Noseworthy
 * @description: Gyro abstraction.
 */

#ifndef WPILIB_DEFINE
#define WPILIB_DEFINE
#include "WPILib.h"
#endif

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
