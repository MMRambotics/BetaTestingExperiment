/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworhy
 * @description: Easy class wrapper for HiTechnic compass.
 */

#include "WPILibrary.h"

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
