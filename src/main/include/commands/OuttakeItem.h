#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"

class OuttakeItem : public frc2::CommandHelper<frc2::CommandBase, OuttakeItem> {
 public:
  OuttakeItem(Intake*);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    Intake* m_intake;
};