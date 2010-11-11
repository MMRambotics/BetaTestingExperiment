/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworhy
 * @description: Easy class wrapper for HiTechnic compass.
 */

#ifndef WPILIB_DEFINE
#define WPILIB_DEFINE
#include "WPILib.h"
#endif

class EasyCompass {
	
	HiTechnicCompass compass;
	
	public:
		
		EasyCompass(int portNumber):
			compass(portNumber)
		{}
	
		float GetHeading() {
			return compass.GetAngle();
		}
	
};
