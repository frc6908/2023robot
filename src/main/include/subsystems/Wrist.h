// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <frc/SPI.h>
#include <AHRS.h>
#include <frc/Encoder.h>

#include <frc/geometry/Rotation2d.h>

#include <frc/drive/DifferentialDrive.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include "Constants.h"

class Wrist : public frc2::SubsystemBase {
 public:
  Wrist();

  void setWristMotor(double);

  void stop();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
    ctre::phoenix::motorcontrol::can::WPI_VictorSPX wristVictor{wrist::kWristVictorPort};
    frc::MotorControllerGroup wristMotor{wristVictor};

};
