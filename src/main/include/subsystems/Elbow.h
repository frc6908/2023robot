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

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include "frc/Encoder.h"

#include "Constants.h"

class Elbow : public frc2::SubsystemBase {
 public:
  Elbow();

  void setElbowMotor(double);

  void stop();

  // double getRotationAngle();

  // void resetEncoder();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  const int ticks_per_revolution = 2048;
  
  rev::CANSparkMax elbowSpark1{elbow::kElbowPort1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax elbowSpark2{elbow::kElbowPort1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};

  frc::MotorControllerGroup elbowMotors{elbowSpark1, elbowSpark2};

  // frc::Encoder elbowEncoder{0, 1};
  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
