// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Shooter.h"
#include "subsystems/Uptake.h"

#include "frc/smartdashboard/SmartDashboard.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Shoot : public frc2::CommandHelper<frc2::CommandBase, Shoot> {
 public:
  Shoot(Shooter*, Uptake*, units::unit_t< units::compound_unit<units::meters, units::inverse<units::seconds>> >, units::unit_t< units::compound_unit<units::meters, units::inverse<units::seconds>> >);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    Shooter* m_shooter;
    Uptake* m_uptake;
    //units::unit_t< units::compound_unit<units::meters, units::inverse<units::seconds> >
    units::unit_t< units::compound_unit<units::meters, units::inverse<units::seconds>> > topVelocity;
    units::unit_t< units::compound_unit<units::meters, units::inverse<units::seconds>> > bottomVelocity;
};
