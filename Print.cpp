/*
 * @author: 
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy (Co-Captain)
 * @description: Easy class for printing to the driver station or other debug
 * methods.
 */

#ifndef WPILIB_DEFINE
#define WPILIB_DEFINE
#include "WPILib.h"
#endif

#ifndef DRIVER_STATION_LCD_DEFINE
#define DRIVER_STATION_LCD_DEFINE
#include "DriverStationLCD.h"
#endif

class Print {
	
	DriverStationLCD *driverStation;
	DriverStationLCD::Line userLines[6];
	
	public:
	
		Print() {
			driverStation = DriverStationLCD::GetInstance();
			userLines[0]  = DriverStationLCD::kUser_Line1;
			userLines[1]  = DriverStationLCD::kUser_Line2;
			userLines[2]  = DriverStationLCD::kUser_Line3;
			userLines[3]  = DriverStationLCD::kUser_Line4;
			userLines[4]  = DriverStationLCD::kUser_Line5;
			userLines[5]  = DriverStationLCD::kUser_Line6;
		}
		
		void PrintText(char *text) {
			driverStation->Printf(userLines[0], 1, text);
		}
		
};
