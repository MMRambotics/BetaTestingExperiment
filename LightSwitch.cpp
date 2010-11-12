/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Monitors a light switch (digital input).
 */

#include "WPILibrary.h"

class LightSwitch {

	DigitalInput lightSwitch;
	
	public:
		
		LightSwitch(int switchPort):
			lightSwitch(switchPort)
		{
		}
	
		bool IsOn() {
			return (lightSwitch.Get());
		}
	
		bool IsOff() {
			return (!lightSwitch.Get());
		}
	
};
