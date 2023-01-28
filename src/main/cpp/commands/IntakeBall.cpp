// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeBall.h"

IntakeBall::IntakeBall(Intake* intake) : 
  m_intake{intake} {
  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(intake);
}

// Called when the command is initially scheduled.
void IntakeBall::Initialize() {
  this->m_intake->stopIntake();
  this->m_intake->stopBottomFeeder();
}

// Called repeatedly when this Command is scheduled to run
void IntakeBall::Execute() {
  this->m_intake->setIntakeMotor(1);
  this->m_intake->setBottomFeederMotor(-0.6);
}

// Called once the command ends or is interrupted.
void IntakeBall::End(bool interrupted) {
  this->m_intake->stopIntake();
  this->m_intake->stopBottomFeeder();
}

// Returns true when the command should end.
bool IntakeBall::IsFinished() {
  return false;
}
