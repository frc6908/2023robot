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
    const int kArmJoystickPort = 1; // elbow joystick
}

namespace gyroBalance {
    const int kGyroPort = 0;
    static constexpr double kAngleSetpoint = 0.0;
    static constexpr double kP = 0.005; // proportional turning constant
    // gyro calibration constant, not final
    // gyro value of 360 is set to correspond to one full revolution
    static constexpr double kVoltsPerDegreePerSecond = 0.0128;
}

namespace arm {
    // Temporary port numbers, change later
    const int kTelescopeTalonPort = 5; 
}

namespace wrist {
    // CHANGE THIS LATER
    const int kWristVictorPort = 14; 
}

namespace elbow {
    const int kElbowPort = 12;
}

namespace elevator {
    // INCORRECT PORTS AGAIN WATCH OUT!!!
    const int kElevatorTalonPort = 10;
    const int kElevatorVenomPort = 15;

    const double kPulleyDiameter = 1.5;  //inches
}

namespace intake {
    // THESE CONSTANTS ARE JUST FILLER CONSTANTS CHANGE THESE LATER
    const int kIntakeVictorPort1 = 11;
    const int kIntakeVictorPort2 = 16;
}

namespace limelight {
    // change kTargetHeight and kCameraHeight
    const double kTargetHeight = 104;
    const double kCameraHeight = 26;
    const double kCameraAngle = 0;
}