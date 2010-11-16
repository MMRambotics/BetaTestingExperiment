/*
 * @author: 
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Easy pneumatic class to control two solenoids.
 */

#include "Headers/WPILibrary.h"

static const bool ON  = true;
static const bool OFF = false;

class EasyPneumatic {

	Solenoid in, out;
	bool     isOut;
	
	public:
		
		EasyPneumatic(int inPort, int outPort):
			in(inPort),
			out(outPort)
		{
			in.Set(OFF);
			out.Set(OFF);
			isOut = false;
		}
		
		void SlideOut() {
			in.Set(OFF);
			out.Set(ON);
			isOut = true;
		}
		
		void SlideIn() {
			in.Set(ON);
			out.Set(OFF);
			isOut = false;
		}
		
		void Toggle() {
			if (isOut)
				SlideIn();
			else
				SlideOut();
			
			isOut = (isOut) ? false : true;
		}
			
};
