// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/UptakeBall.h"

UptakeBall::UptakeBall(Uptake* uptake) : 
  m_uptake{uptake} {
  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(uptake);
}

// Called when the command is initially scheduled.
void UptakeBall::Initialize() {
  this->m_uptake->stopUptake();
}

// Called repeatedly when this Command is scheduled to run
void UptakeBall::Execute() {
  this->m_uptake->setUptakeMotor(0.6);
}

// Called once the command ends or is interrupted.
void UptakeBall::End(bool interrupted) {
  this->m_uptake->stopUptake();
}

// Returns true when the command should end.
bool UptakeBall::IsFinished() {
  return false;
}
