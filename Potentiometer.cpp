/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Grabs a value from a potentiometer.
 */

#ifndef WPILIB_DEFINE
#define WPILIB_DEFINE
#include "WPILib.h"
#endif

class Potentiometer {
	
	AnalogChannel pot;
	
	public:
	
		Potentiometer(int portNumber):
			pot(portNumber)
		{
		}

		bool GreaterThanThreshold(float threshold) {
			return (pot.GetVoltage() > threshold);
		}
		
		bool LessThanThreshold(float threshold) {
			return (pot.GetVoltage() < threshold);
		}
		
		float GetRawVoltage() {
			return pot.GetVoltage();
		}
		
};
