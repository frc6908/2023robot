// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Limelight.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class PIDRotateAngle : public frc2::CommandHelper<frc2::CommandBase, PIDRotateAngle> {
 public:
  PIDRotateAngle(Drivetrain*, Limelight*);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    Drivetrain* m_drivetrain;
    Limelight* m_limelight;

    double setpoint;
    double kP = 0.08; // 0.15; // 0.03;// 0.025; // 0.06//0.0825;//0.075;// 0.0875; // 0.09; //0.1; // 0.1125;//0.125; //0.15;
    double kD = 0.00975; // 0.01;//0.002; //0.011;// 0.009875;// 0.00975;
    double kI = 0; //0.005;
    // Use 0.0825 & 0.00975 for drivetrain rotation
    double previousError;
    double error;
    double cumError;
    double stopAccumulator;
};