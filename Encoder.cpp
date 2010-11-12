/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Easy encoder class.
 */

#include "Headers/WPILibrary.h"

class EasyEncoder {
	
	Encoder encoder;
	
	public:
		
		EasyEncoder(int aPortNumber, int bPortNumber):
			encoder(aPortNumber, bPortNumber)
		{}
	
};
