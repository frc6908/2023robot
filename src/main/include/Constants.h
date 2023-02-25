// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace drivetrain {
    // Temporary port numbers; change later.
    const int kLeftDriveSparkPort1 = 15;
    const int kLeftDriveSparkPort2 = 14;
    const int kLeftDriveSparkPort3 = 13;

    const int kRightDriveSparkPort1 = 12;
    const int kRightDriveSparkPort2 = 11;
    const int kRightDriveSparkPort3 = 10; 

    const int kWheelDiameter = 6;   //inches
    
    const double kDT = 0.02;
}

namespace oi {
    const int kDriveJoystickPort = 0;   // drive joystick
    //const int kDriveControllerPort = 1; // operator ps5 controller
}

namespace intake {
    // THESE CONSTANTS ARE JUST FILLER CONSTANTS CHANGE THESE LATER
    const int kIntakeTalonPort1 = 0;
    const int kIntakeTalonPort2 = 1;
}