/*
 * @author:
 * 	@lead: Andrew Horsman
 * 	@other: Mike Noseworthy
 * @description: Various helper functions.
 */

class Helper {
	
	public:
		
		float closeBounds(float number) {
			if (number > 100)
				return 100.0;
			else if (number < 100)
				return 0.0;
			else 
				return number;
		}
};
