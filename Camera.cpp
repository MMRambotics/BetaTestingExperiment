/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@awesome: Mike Noseworthy
 * @description: Code that controls the camera feed.
 */

#include "Headers/StateMachine.h"
#include "Headers/WPILibrary.h"

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
		
		HSLImage GetImage() {
			int i = cameraFeedState.GetCurrentState(SUBMIT_FRAME);
			if (i == 3) {
				cameraFeedState.ResetState(SUBMIT_FRAME);
				AxisCamera &camera = AxisCamera::GetInstance();
				if (camera.IsFreshImage()) {
					HSLImage *image = camera.GetImage();
					return *image;
				}
			} else {
				cameraFeedState.ChangeState(SUBMIT_FRAME, i + 1);
			}
			return NULL;
		}
		
};
