// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

#include <frc/shuffleboard/Shuffleboard.h>


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  

  m_chooser.SetDefaultOption("Stationary Auto", &m_stationaryauto);
  m_chooser.AddOption("Slow Auto", &m_slowauto);
  m_chooser.AddOption("Gyro Auto", &m_gyroauto);

  frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser).WithWidget(frc::BuiltInWidgets::kComboBoxChooser);

  // Configure the button bindings
  ConfigureButtonBindings();

  // need lambda function to capture the value of the double function for continuous data getting 
  m_drivetrain.SetDefaultCommand(ArcadeDrive(&m_drivetrain, [this] { return -m_joystick.GetY(); }, [this] { return m_joystick.GetX(); }, [this] { return m_joystick.GetThrottle(); }));
}

// change button bindings LATER
void RobotContainer::ConfigureButtonBindings() {
   //drivetrain
  frc2::JoystickButton flipDriveTrain(&m_joystick, 8);
  flipDriveTrain.WhenPressed(new FlipDrivetrain(&m_drivetrain));
  
  //gyro control
  //frc2::JoystickButton gyroBalance(&m_joystick, 6);
  //gyroBalance.WhileHeld(new Gyro(&m_drivetrain));

  //intake/outtake
  frc2::JoystickButton intake(&m_joystick, 1);
  intake.WhileHeld(new IntakeItem(&m_intake));
  frc2::JoystickButton outtake(&m_joystick, 2);
  outtake.WhileHeld(new OuttakeItem(&m_intake));

  //preset elevator stages
  frc2::JoystickButton elevatorLowHeight(&m_joystick,12);
  elevatorLowHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 0));
  frc2::JoystickButton elevatorMidHeight(&m_joystick,10);
  elevatorMidHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 1));
  frc2::JoystickButton elevatorHighHeight(&m_joystick,11);
  elevatorHighHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 2));
  frc2::JoystickButton elevatorPlayerHeight(&m_joystick,9);
  elevatorPlayerHeight.WhenPressed(new SetElevatorHeight(&m_elevator, 3));

  //elevator manual
  frc2::JoystickButton elevatorUp(&m_joystick, 6);
  elevatorUp.WhileHeld(new ElevatorMotion(&m_elevator, true, m_joystickArm.GetThrottle()));
  frc2::JoystickButton elevatorDown(&m_joystick, 4);
  elevatorDown.WhileHeld(new ElevatorMotion(&m_elevator, false, m_joystickArm.GetThrottle()));

  //arm telescope
  frc2::JoystickButton wrenchIn(&m_joystickArm, 1);
  wrenchIn.WhileHeld(new Extend(&m_arm, true));
  frc2::JoystickButton wrenchOut(&m_joystickArm, 2);
  wrenchOut.WhileHeld(new Extend(&m_arm, false));

  //wrist movement
  frc2::JoystickButton wristRight(&m_joystickArm, 5);
  wristRight.WhileHeld(new Twist(&m_wrist, true));
  frc2::JoystickButton wristLeft(&m_joystickArm, 3);
  wristLeft.WhileHeld(new Twist(&m_wrist, false));

  //elbow movement
  frc2::JoystickButton elbowForward(&m_joystickArm, 6);
  elbowForward.WhileHeld(new MoveElbow(&m_elbow, true));
  frc2::JoystickButton elbowBack(&m_joystickArm, 4);
  elbowBack.WhileHeld(new MoveElbow(&m_elbow, false));

  //limelight
  frc2::JoystickButton PIDTall(&m_joystick, 3);
  PIDTall.WhenPressed(new PIDRotateAngle(&m_drivetrain, &m_limelight, 10.636));
  frc2::JoystickButton PIDMiddle(&m_joystick, 5);
  PIDMiddle.WhenPressed(new PIDRotateAngle(&m_drivetrain, &m_limelight, 15.422));
}

frc2::Command* RobotContainer::GetAutonomousCommand() { 
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
  return m_chooser.GetSelected();
}


