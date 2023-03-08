// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Elevator.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class SetElevatorHeight : public frc2::CommandHelper<frc2::CommandBase, SetElevatorHeight> {
 public:
  SetElevatorHeight(Elevator*, int);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    Elevator* m_elevator;
    int stage;
    double currentHeight = 0;
    
    const int lowStageHeight = 0; //height inches
    const int midStageHeight = 36;
    const int highStageHeight = 48;
    const int playerHeight = 39;
};
