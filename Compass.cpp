/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworhy
 * @description: Easy class wrapper for HiTechnic compass.
 */

#include "Headers/WPILibrary.h"

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
