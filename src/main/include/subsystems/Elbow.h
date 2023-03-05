// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include "Constants.h"

class Elbow : public frc2::SubsystemBase {
 public:
  Elbow();

  void setElbowMotors(double);

  void stop();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX elbowTalon{elbow::kElbowPort};

  frc::MotorControllerGroup elbowMotor{elbowTalon};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
