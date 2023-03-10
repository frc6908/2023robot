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
  m_drivetrain.SetDefaultCommand(ArcadeDrive(&m_drivetrain, [this] { return -m_joystick.GetY(); }, [this] { return m_joystick.GetX(); }, [this] { return m_joystick.GetThrottle(); }));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  //mapping button numbers
  frc2::JoystickButton flipDriveTrain(&m_joystick, 7);

  frc2::JoystickButton gyroBalance(&m_joystick,4);

  //preset elevator stages
  frc2::JoystickButton elevatorLowHeight(&m_joystick, 12);
  elevatorLowHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 0, m_joystickArm.GetThrottle()));
  frc2::JoystickButton elevatorMidHeight(&m_joystick, 10);
  elevatorMidHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 1, m_joystickArm.GetThrottle()));
  frc2::JoystickButton elevatorHighHeight(&m_joystick, 11);
  elevatorHighHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 2, m_joystickArm.GetThrottle()));
  frc2::JoystickButton elevatorPlayerHeight(&m_joystick, 9);
  elevatorPlayerHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 3, m_joystickArm.GetThrottle()));

  //elevator manual
  frc2::JoystickButton elevatorUp(&m_joystick, 6);
  elevatorUp.WhileHeld(new ElevatorMotion(&m_elevator, true, m_joystickArm.GetThrottle()));
  frc2::JoystickButton elevatorDown(&m_joystick, 4);
  elevatorDown.WhileHeld(new ElevatorMotion(&m_elevator, false, m_joystickArm.GetThrottle()));




  //maping button functions  
  flipDriveTrain.WhenPressed(new FlipDrivetrain(&m_drivetrain));
  gyroBalance.WhileHeld(new Gyro(&m_drivetrain));
}

frc2::Command* RobotContainer::GetAutonomousCommand() { 
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
  return &m_driveAutoCommand;
}


