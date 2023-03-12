// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"

#include <frc2/command/Command.h>

#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

#include "subsystems/Drivetrain.h"
#include "subsystems/Arm.h"
#include "subsystems/Elevator.h"
#include "subsystems/Elbow.h"
#include "subsystems/Intake.h"
#include "subsystems/Wrist.h"
#include "subsystems/Limelight.h"

#include "commands/ArcadeDrive.h"
#include "commands/GyroAuto.h"
#include "commands/FlipDrivetrain.h"
#include "commands/Gyro.h"
#include "commands/Extend.h"
#include "commands/ElevatorMotion.h"
#include "commands/MoveElbow.h"
#include "commands/IntakeItem.h"
#include "commands/OuttakeItem.h"
#include "commands/Twist.h"
#include "commands/SetElevatorHeight.h"
#include "commands/PIDRotateAngle.h"
#include "commands/SlowAuto.h"
#include "commands/StationaryAuto.h"

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>

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
  //example things
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  //drivetrain
  Drivetrain m_drivetrain;
  
  //Arm
  Arm m_arm;

  //elevator
  Elevator m_elevator;

  //Elbow
  Elbow m_elbow;

  //intake

  Intake m_intake;

  //wrist

  Wrist m_wrist;

  // limelight
  Limelight m_limelight;

  // autonomous modes
  StationaryAuto m_stationaryauto{&m_drivetrain};
  SlowAuto m_slowauto{&m_drivetrain};
  GyroAuto m_gyroauto{&m_drivetrain};

  // chooser for autonomous routines
  frc::SendableChooser<frc2::Command*> m_chooser;

  //joystick
  frc::Joystick m_joystick{oi::kDriveJoystickPort};
  frc::Joystick m_joystickArm{oi::kArmJoystickPort};

  void ConfigureButtonBindings();
};
