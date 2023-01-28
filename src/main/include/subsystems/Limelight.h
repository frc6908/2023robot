// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <cmath>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include "frc/smartdashboard/Smartdashboard.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"
#include "wpi/span.h"

#include "Constants.h"


class Limelight: public frc2::SubsystemBase {
 public:
  Limelight();

  double getHorizontalOffset();

  double getVerticalOffset();

  double getArea();

  double getSkew();

  double getDistance();

  bool hasValidTargetPose2d();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  std::shared_ptr<nt::NetworkTable> limelightTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");


  frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("SmartDashboard");
};
