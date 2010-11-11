/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Easy encoder class.
 */

#ifndef WPILIB_DEFINE
#define WPILIB_DEFINE
#include "WPILib.h"
#endif

class EasyEncoder {
	
	Encoder encoder;
	
	public:
		
		EasyEncoder(int aPortNumber, int bPortNumber):
			encoder(aPortNumber, bPortNumber)
		{}
	
};
