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

#ifndef STATE_MACHINE_DEFINE
#define STATE_MACHINE_DEFINE
#include "StateMachine.cpp"
#endif

class EasyCamera {

	StateMachine cameraFeedState;
	
	// State constants.
	static const int SUBMIT_FRAME = 1;
	
	public:
	
		EasyCamera():
			cameraFeedState()
		{
			AxisCamera &camera = AxisCamera::GetInstance();
			camera.WriteResolution(AxisCamera::kResolution_320x240);
			camera.WriteCompression(0);
			camera.WriteBrightness(0);
			
			cameraFeedState.RegisterState(SUBMIT_FRAME, 1);
		}
		
		void GetImage() {
			int i = cameraFeedState.GetCurrentState(SUBMIT_FRAME);
			if (i == 3) {
				AxisCamera &camera = AxisCamera::GetInstance();
				if (camera.IsFreshImage()) {
					HSLImage *image = camera.GetImage();
				}
				cameraFeedState.ResetState(SUBMIT_FRAME);
			} else {
				cameraFeedState.ChangeState(SUBMIT_FRAME, i + 1);
			}
		}
		
};
