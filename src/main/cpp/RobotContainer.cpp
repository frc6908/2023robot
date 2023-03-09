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

// change button bindings LATER
void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton flipDriveTrain(&m_joystick, 7);
  frc2::JoystickButton gyroBalance(&m_joystick, 3);
  frc2::JoystickButton elbowRight(&m_joystick, 4);
  frc2::JoystickButton elbowLeft(&m_joystick, 6);
  frc2::JoystickButton gyroBalance(&m_joystick, 4);
  frc2::JoystickButton extend(&m_joystick, 10);
  frc2::JoystickButton retract(&m_joystick, 11);
  frc2::JoystickButton elevatorUp(&m_joystick, 3);
  frc2::JoystickButton elevatorDown(&m_joystick, 5);
  frc2::JoystickButton intake(&m_joystick, 1);    
  frc2::JoystickButton outtake(&m_joystick, 2);
  //change these button
  frc2::JoystickButton twistRight(&m_joystick, 8);
  frc2::JoystickButton twistLeft(&m_joystick, 9);


  elbowRight.WhileHeld(new MoveElbow(&m_elbow, true));
  elbowLeft.WhileHeld(new MoveElbow(&m_elbow, false));
  flipDriveTrain.WhenPressed(new FlipDrivetrain(&m_drivetrain));
  gyroBalance.WhileHeld(new Gyro(&m_drivetrain));
  extend.WhileHeld(new Extend(&m_arm, true));
  retract.WhileHeld(new Extend(&m_arm, false));
  elevatorUp.WhileHeld(new ElevatorMotion(&m_elevator, true));
  elevatorDown.WhileHeld(new ElevatorMotion(&m_elevator, false));  
  intake.WhileHeld(new IntakeItem(&m_intake));
  outtake.WhileHeld(new OuttakeItem(&m_intake));
  twistLeft.WhileHeld(new Twist(&m_wrist, false));
  twistLeft.WhileHeld(new Twist(&m_wrist, true));
  // need to add limelight and wrist commands/subsystems
}

frc2::Command* RobotContainer::GetAutonomousCommand() { 
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
  return &m_driveAutoCommand;
}


