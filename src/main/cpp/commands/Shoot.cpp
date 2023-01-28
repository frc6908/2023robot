// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Shoot.h"

Shoot::Shoot(Shooter* shooter, Uptake* uptake, units::unit_t< units::compound_unit<units::meters, units::inverse<units::seconds>> > topV, units::unit_t< units::compound_unit<units::meters, units::inverse<units::seconds>> > bottomV) : 
  m_shooter{shooter}, m_uptake{uptake}, topVelocity{topV}, bottomVelocity{bottomV} {
  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(shooter);
  AddRequirements(uptake);
}

// Called when the command is initially scheduled.
void Shoot::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
  //frc::SmartDashboard::PutNumber("topVelocity", this->m_shooter->getTopVelocity());
  //frc::SmartDashboard::PutNumber("bottomVelocity", this->m_shooter->getBottomVelocity());
  double tv = this->m_shooter->getTopVelocity();
  double bv = this->m_shooter->getBottomVelocity();

  if (this->m_shooter->withinTolerance(tv, topVelocity.value(), 3)) {
      // DO SOMETHING 
      this->m_uptake->setUptakeMotor(0.6);
      this->m_uptake->setTopFeederMotor(0.7);
  }

  this->m_shooter->getTPID()->SetSetpoint(this->topVelocity.value());
  this->m_shooter->getBPID()->SetSetpoint(this->bottomVelocity.value());

  units::voltage::volt_t ctop{this->m_shooter->getTPID()->Calculate(tv)};
  units::voltage::volt_t cbot{this->m_shooter->getBPID()->Calculate(bv)};

  this->m_shooter->setTopMotorVoltage(ctop + this->m_shooter->getTFF()->Calculate(topVelocity));
  this->m_shooter->setBottomMotorVoltage(cbot + this->m_shooter->getBFF()->Calculate(bottomVelocity));
}

// Called once the command ends or is interrupted.
void Shoot::End(bool interrupted) {
  units::voltage::volt_t stopVoltage{0.0};
  this->m_shooter->setTopMotorVoltage(stopVoltage);
  this->m_shooter->setBottomMotorVoltage(stopVoltage);
  this->m_uptake->setTopFeederMotor(0);
  this->m_uptake->setUptakeMotor(0);
}

// Returns true when the command should end.
bool Shoot::IsFinished() {
  return false;
}
