// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"
#include <cmath> 

Shooter::Shooter() {
  // Implementation of subsystem constructor goes here.
}

void Shooter::setBottomMotorVoltage(units::voltage::volt_t bottomVoltage){
  bottomSpark.SetVoltage(bottomVoltage);
  
}

void Shooter::setTopMotorVoltage(units::voltage::volt_t topVoltage){
  topSpark.SetVoltage(topVoltage);
}

double Shooter::getTopVelocity() {
  return topEncoder.GetVelocity() / 60;
}

double Shooter::getBottomVelocity() {
  return bottomEncoder.GetVelocity() / 60; // check these definitions for syntax i don't have the autocomplete rn
}

frc::PIDController* Shooter::getTPID() {
  return &tpid;
}

frc::PIDController* Shooter::getBPID() {
  return &bpid;
}

frc::SimpleMotorFeedforward<units::meters>* Shooter::getTFF() {
  return &tff;
}

frc::SimpleMotorFeedforward<units::meters>* Shooter::getBFF() {
  return &bff;
}

void Shooter::stopShooter(){
  bottomSpark.StopMotor();
  topSpark.StopMotor();
}

void Shooter::Periodic() { }

bool Shooter::withinTolerance(double a, double b, double t) {
  return std::abs(a - b) <= t;
}