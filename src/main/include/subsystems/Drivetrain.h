// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <CANVenom.h>
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

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  void setDriveMotors(double, double);

  void arcadeDrive(double, double);

  void stop();
  
  void flipDT();

  frc::Rotation2d getHeading();

  double getHeadingAsAngle();

  void resetEncoders();

  double getLeftEncoderDistance();

  double getRightEncoderDistance();

  double venomTicksToInches(double);

  void resetGyro();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX leftDriveTalon{drivetrain::kLeftDriveTalonPort};
  frc::CANVenom leftDriveVenom{drivetrain::kLeftDriveVenomPort};

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX rightDriveTalon{drivetrain::kRightDriveTalonPort};
  frc::CANVenom rightDriveVenom{drivetrain::kRightDriveVenomPort};

  frc::MotorControllerGroup leftMotors{leftDriveTalon, leftDriveVenom};
  frc::MotorControllerGroup rightMotors{rightDriveTalon, rightDriveVenom};

  //frc::DifferentialDrive drive{leftMotors, rightMotors};

  AHRS gyro{frc::SPI::Port::kMXP};

  bool flipped = false;

  frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("Test");

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
