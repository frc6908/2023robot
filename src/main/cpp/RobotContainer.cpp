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
  //mapping button numbers
  frc2::JoystickButton flipDriveTrain(&m_joystick, 7);
<<<<<<< Updated upstream

  frc2::JoystickButton gyroBalance(&m_joystick,4);

  //manual move elevator
  frc2::JoystickButton elevatorUp(&m_joystick, 3);
  frc2::JoystickButton elevatorDown(&m_joystick, 5);

  //preset elevator stages
  frc2::JoystickButton elevatorLowHeight(&m_joystick,12);
  frc2::JoystickButton elevatorMidHeight(&m_joystick,10);
  frc2::JoystickButton elevatorHighHeight(&m_joystick,11);
  frc2::JoystickButton elevatorPlayerHeight(&m_joystick,9);



  //maping button functions
=======
  frc2::JoystickButton gyroBalance(&m_joystick, 4);


  frc2::JoystickButton Twist(&m_joystick, 11);
  
>>>>>>> Stashed changes
  flipDriveTrain.WhenPressed(new FlipDrivetrain(&m_drivetrain));
  gyroBalance.WhileHeld(new Gyro(&m_drivetrain));

  elevatorUp.WhileHeld(new ElevatorMotion(&m_elevator, true));
  elevatorDown.WhileHeld(new ElevatorMotion(&m_elevator, false));
  
  elevatorLowHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 0));
  elevatorMidHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 1));
  elevatorHighHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 2));
  elevatorPlayerHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 3));
}

frc2::Command* RobotContainer::GetAutonomousCommand() { 
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
  return &m_driveAutoCommand;
}


