/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@awesome: Mike Noseworthy
 * @description: Code that controls the camera feed.
 */

#ifndef WPILIB_DEFINE
#define WPILIB_DEFINE
#include "WPILib.h"
#endif

class EasyCamera {

	public:
	
		EasyCamera() {
			AxisCamera &camera = AxisCamera::GetInstance();
			camera.WriteResolution(AxisCamera::kResolution_320x240);
			camera.WriteCompression(0);
			camera.WriteBrightness(0);
		}
		
		void GetImage() {
			AxisCamera &camera = AxisCamera::GetInstance();
			if (camera.IsFreshImage()) {
				HSLImage *image = camera.GetImage();
			}
		}
		
};
