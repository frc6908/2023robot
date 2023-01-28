// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SetShoot.h"

SetShoot::SetShoot(Shooter* shooter, Uptake* uptake, units::voltage::volt_t topV, units::voltage::volt_t bottomV) : 
  m_shooter{shooter}, m_uptake{uptake}, topVoltage{topV}, bottomVoltage{bottomV} {
  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(shooter);
  AddRequirements(uptake);
}

// Called when the command is initially scheduled.
void SetShoot::Initialize() {
  
  units::voltage::volt_t stopVoltage{0.0};
  this->m_shooter->setTopMotorVoltage(stopVoltage);
  this->m_shooter->setBottomMotorVoltage(stopVoltage);
  this->m_uptake->setTopFeederMotor(0);
  this->m_uptake->setUptakeMotor(0);
}

// Called repeatedly when this Command is scheduled to run
void SetShoot::Execute() {
  frc::SmartDashboard::PutNumber("bottomVelocity", m_shooter->getBottomVelocity());
  this->m_shooter->setTopMotorVoltage(topVoltage);
  this->m_shooter->setBottomMotorVoltage(bottomVoltage);
  this->m_uptake->setTopFeederMotor(0.5);
  this->m_uptake->setUptakeMotor(0.6);

}

// Called once the command ends or is interrupted.
void SetShoot::End(bool interrupted) {
  units::voltage::volt_t stopVoltage{0.0};
  this->m_shooter->setTopMotorVoltage(stopVoltage);
  this->m_shooter->setBottomMotorVoltage(stopVoltage);
  this->m_uptake->setTopFeederMotor(0);
  this->m_uptake->setUptakeMotor(0);
}

// Returns true when the command should end.
bool SetShoot::IsFinished() {
  return false;
}
