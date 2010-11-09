/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Monitors a light switch (digital input).
 */

#ifndef WPILIB_DEFINE
#define WPILIB_DEFINE
#include "WPILib.h"
#endif

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
