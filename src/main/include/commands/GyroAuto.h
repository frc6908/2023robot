// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class GyroAuto : public frc2::CommandHelper<frc2::CommandBase, GyroAuto> {
 public:
  GyroAuto(Drivetrain*);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    int t;
    Drivetrain* m_drivetrain;
    bool gyromode = false;
    double error = 0;
    double cumError = 0;
    double prevError = 0;
    // incorrect values, change on friday
    double kP = 0.04;
    double kD = 0.00975;
    double kI = 0;
};
