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
    const int kLeftDriveSparkPort1 = 1;
    const int kLeftDriveSparkPort2 = 2;
    const int kLeftDriveSparkPort3 = 3;

    const int kRightDriveSparkPort1 = 19;
    const int kRightDriveSparkPort2 = 18;
    const int kRightDriveSparkPort3 = 17; 

    const int kWheelDiameter = 6;   //inches
    
    const double kDT = 0.02;
}

namespace oi {
    const int kDriveJoystickPort = 0;   // drive joystick
    //const int kDriveControllerPort = 1; // operator ps5 controller
}

namespace gyroBalance {
    const int kGyroPort = 0;
    static constexpr double kAngleSetpoint = 0.0;
    static constexpr double kP = 0.005; // proportional turning constant
    // gyro calibration constant, not final
    // gyro value of 360 is set to correspond to one full revolution
    static constexpr double kVoltsPerDegreePerSecond = 0.0128;
}

namespace elevator {
    // INCORRECT PORTS AGAIN WATCH OUT!!!
    const int kElevatorTalonPort = 0;
    const int kElevatorVenomPort = 1;

    const double kPulleyDiameter = 1.5;  //inches
}

namespace elbow {
    const int kElbowPort = 12;
}