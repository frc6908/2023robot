// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>
#include <rev/CANSparkMaxLowLevel.h>
#include <rev/SparkMaxRelativeEncoder.h>
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

class SwerveModule : public frc2::SubsystemBase {
 public:
  SwerveModule();

  void setDesiredState(double, double);

  void stop();
  
  double getRotate();

  double getForward();

  void resetEncoders();

  double ticksToMeters();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  rev::CANSparkMax RotateSpark1{drivetrain::kLeftDriveSparkPort1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};

  rev::CANSparkMax ForwardSpark1{drivetrain::kRightDriveSparkPort1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};

  rev::SparkMaxRelativeEncoder rotateEncoder = RotateSpark1.GetEncoder();
  rev::SparkMaxRelativeEncoder forwardEncoder = ForwardSpark1.GetEncoder();

  //frc::DifferentialDrive drive{leftMotors, rightMotors};

  frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("Test");

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
