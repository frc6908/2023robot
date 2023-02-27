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

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  void setDriveMotors(double, double);

  void arcadeDrive(double, double);

  void stop();
  
  void flipDT();

  frc::Rotation2d getHeading();

  double getHeadingAsAngle();

  frc::Rotation2d getPitch();

  double getPitchAsAngle();

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
  rev::CANSparkMax leftSpark1{drivetrain::kLeftDriveSparkPort1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax leftSpark2{drivetrain::kLeftDriveSparkPort2, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax leftSpark3{drivetrain::kLeftDriveSparkPort3, rev::CANSparkMaxLowLevel::MotorType::kBrushless};

  rev::CANSparkMax rightSpark1{drivetrain::kRightDriveSparkPort1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax rightSpark2{drivetrain::kRightDriveSparkPort2, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax rightSpark3{drivetrain::kRightDriveSparkPort3, rev::CANSparkMaxLowLevel::MotorType::kBrushless};

  rev::SparkMaxRelativeEncoder leftEncoder = leftSpark1.GetEncoder();
  rev::SparkMaxRelativeEncoder rightEncoder = rightSpark1.GetEncoder();


  frc::MotorControllerGroup leftMotors{leftSpark1, leftSpark2, leftSpark3};
  frc::MotorControllerGroup rightMotors{rightSpark1, rightSpark2, rightSpark3};

  //frc::DifferentialDrive drive{leftMotors, rightMotors};

  AHRS gyro{frc::SPI::Port::kMXP};

  bool flipped = false;

  frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("Test");

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
