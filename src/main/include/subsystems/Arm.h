// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <frc/SPI.h>
#include <AHRS.h>

#include <frc/geometry/Rotation2d.h>

#include <frc/drive/DifferentialDrive.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include "Constants.h"

class Arm : public frc2::SubsystemBase {
    public:
        Arm();

        void setTelescopeMotor(double);

        void extension(int);

        void stop();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
        void Periodic() override;

    private:
        int currentMode = 0;

        ctre::phoenix::motorcontrol::can::WPI_TalonSRX telescopeTalon{arm::kTelescopeTalonPort};

        frc::MotorControllerGroup telescopeMotor{telescopeTalon};

        frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("Test");
        // Components (e.g. motor controllers and sensors) should generally be
            // declared private and exposed only through public methods.
};