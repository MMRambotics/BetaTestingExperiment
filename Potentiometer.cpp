/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Grabs a value from a potentiometer.
 */

#include "Headers/WPILibrary.h"

class Potentiometer {
	
	AnalogChannel pot;
	float         range,
	              lowerBound;
	
	public:
	
		Potentiometer(int portNumber, float lowerBoundVoltage = -1.0, float upperBoundVoltage = -1.0):
			pot(portNumber)
		{
			if (lowerBoundVoltage > upperBoundVoltage)
				range = lowerBoundVoltage - upperBoundVoltage;
			else if (upperBoundVoltage > lowerBoundVoltage)
				range = upperBoundVoltage - lowerBoundVoltage;
			
			lowerBound = lowerBoundVoltage;
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
		
		float CalculatePosition() {
			float current = GetRawVoltage();
			float differenceFromLower = current - lowerBound;
			
			if (differenceFromLower == 0.0) return 0;
			float positionPercentile = 100 / (range / differenceFromLower);
			return positionPercentile;
		}
};
