// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ArcadeDrive.h"
#include <frc/MathUtil.h>
#include <cmath>

double normalize(double min, double max, double a, double b, double x) {
  return (((b-a) * (x-min)) / (max-min)) + a;
}

ArcadeDrive::ArcadeDrive(Drivetrain* drivetrain, std::function<double()> throttle, std::function<double()> turn,   std::function<double()> acceleration) : 
  m_drivetrain{drivetrain}, m_acceleration{std::move(acceleration)}, m_turn{std::move(turn)}, m_throttle{std::move(throttle)} {
  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(drivetrain);
}

// Called when the command is initially scheduled.
void ArcadeDrive::Initialize() {
  this->m_drivetrain->stop();
}

// Called repeatedly when this Command is scheduled to run
void ArcadeDrive::Execute() {
  int tSign = m_turn() < 0 ? -1 : 1;

  double turn = std::pow(m_turn(), 2) * tSign;

  double throttle = std::abs(m_throttle()) < 0.1 ? 0 : m_throttle();

  double speedMultiplier = normalize(1, -1, 0.2, 1, m_acceleration());
  
  //tab.Add("LeftM", ( (throttle + turn) * speedMultiplier) );
  //tab.Add("RightM",  ( (throttle - turn) * speedMultiplier) );
  frc::SmartDashboard::PutNumber("leftMotor", ( (throttle + turn) * speedMultiplier));
  frc::SmartDashboard::PutNumber("rightMotor", ( (throttle - turn) * speedMultiplier));
  this->m_drivetrain->setDriveMotors(((throttle + turn) * speedMultiplier), ((throttle - turn) * speedMultiplier));  
} 

// Called once the command ends or is interrupted.
void ArcadeDrive::End(bool interrupted) {
  this->m_drivetrain->stop();
}

// Returns true when the command should end.
bool ArcadeDrive::IsFinished() {
  return false;
}
