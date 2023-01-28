// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Uptake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Limelight.h"

#include "commands/ArcadeDrive.h"
#include "commands/IntakeBall.h"
#include "commands/OuttakeBall.h"
#include "commands/UptakeBall.h"
#include "commands/Shoot.h"
#include "commands/SetShoot.h"
#include "commands/DriveAuton.h"
#include "commands/FlipDrivetrain.h"
#include "commands/PIDRotateAngle.h"

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/PS4Controller.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  Drivetrain m_drivetrain;
 

  Intake m_intake;
  Uptake m_uptake;
  Shooter m_shooter;
  Limelight m_limelight;
  DriveAuton m_driveAutoCommand{&m_drivetrain, &m_shooter, &m_uptake};

  frc::Joystick m_joystick{oi::kDriveJoystickPort};
  frc::PS4Controller m_controller{oi::kDriveControllerPort};

  

  void ConfigureButtonBindings();
};
