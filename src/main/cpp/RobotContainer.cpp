// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  
  // Configure the button bindings
  ConfigureButtonBindings();

  // need lambda function to capture the value of the double function for continuous data getting 
  m_drivetrain.SetDefaultCommand(ArcadeDrive(&m_drivetrain, [this] { return -m_joystick.GetY(); }, [this] { return m_joystick.GetX(); }, [this] { return m_joystick.GetThrottle(); }
  ));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  
  frc2::JoystickButton uptakeBall(&m_joystick, 2); //Side Button
  frc2::JoystickButton intakeBall(&m_joystick, 5);
  frc2::JoystickButton outtakeBall(&m_joystick, 6);
  //frc2::JoystickButton flipDriveTrain(&m_joystick, 7);
  frc2::JoystickButton shoot50(&m_joystick, 9);
  frc2::JoystickButton shoot60(&m_joystick, 10);
  frc2::JoystickButton shoot70(&m_joystick, 11);
  frc2::JoystickButton shoot80(&m_joystick, 12);
  frc2::JoystickButton shoot90(&m_joystick, 1);
  frc2::JoystickButton flipDrivetrain(&m_joystick, 7);
  frc2::JoystickButton rotateToTarget(&m_joystick, 8);


  intakeBall.WhileHeld(new IntakeBall(&m_intake));
  uptakeBall.WhileHeld(new UptakeBall(&m_uptake));
  outtakeBall.WhileHeld(new OuttakeBall(&m_intake));
  //flipDrivetrain.WhenPressed(m_drivetrain.flipDT(), &m_drivetrain);
  shoot50.WhileHeld(new Shoot(&m_shooter, &m_uptake, units::velocity::meters_per_second_t{-50.0}, units::velocity::meters_per_second_t{50.0}));
  shoot80.WhileHeld(new Shoot(&m_shooter, &m_uptake, units::velocity::meters_per_second_t{-80.0}, units::velocity::meters_per_second_t{70.0}));
  shoot60.WhileHeld(new Shoot(&m_shooter, &m_uptake, units::velocity::meters_per_second_t{-60.0}, units::velocity::meters_per_second_t{60.0}));
  shoot70.WhileHeld(new Shoot(&m_shooter, &m_uptake, units::velocity::meters_per_second_t{-70.0}, units::velocity::meters_per_second_t{70.0}));
  shoot90.WhileHeld(new Shoot(&m_shooter, &m_uptake, units::velocity::meters_per_second_t{-90.0}, units::velocity::meters_per_second_t{90.0}));
  flipDrivetrain.WhileHeld(new FlipDrivetrain(&m_drivetrain));
  rotateToTarget.WhileHeld(new PIDRotateAngle(&m_drivetrain, &m_shooter, &m_limelight));
}

frc2::Command* RobotContainer::GetAutonomousCommand() { 
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
  return &m_driveAutoCommand;
}


