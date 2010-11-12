MMRambotics 2010-2011 Beta 
==========================

MMRambotics
-----------

Team 2200 MMRambotics has been chosen to be a control system software beta 
tester for Wind River C++ in the 2010-2011 FIRST Robotics Competition season.

Overview
--------

The code presented in this repository is a collection of experiments designed to
test a variety of classes in the C++ WPI library.

Testing Done
------------

We've experimented with the following classes and aspects of programming with 
the WPI library in Wind River.

-Accelerometer
	-Using the ADXL335 (FRC 2009 KOP) accelerometer.
	-Core functions: SetSensitivity, SetZero, GetAcceleration
-AxisCamera
	-Getting a camera feed on the dashboard.
	-Customized dashboard and configuration of the Axis Camera was required for
	 optimal performance.
		-Removed unnecessary graphs from the Dashboard.
		-Set the Axis Camera to 10FPS.
	-Core functions: GetInstance (includes constructor), WriteResolution, 
	 WriteBrightness, WriteCompression, GetImage, IsFreshImage