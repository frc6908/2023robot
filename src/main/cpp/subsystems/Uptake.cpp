// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Uptake.h"

Uptake::Uptake() {
  // Implementation of subsystem constructor goes here.
}

void Uptake::setUptakeMotor(double UptakeSpeed){
  UptakeVictor.Set(UptakeSpeed);
}

void Uptake::setTopFeederMotor(double FeederSpeed){
  TopFeederVictor.Set(FeederSpeed);
}

void Uptake::stopUptake(){
  UptakeVictor.Set(0);
}

void Uptake::stopTopFeeder(){
  TopFeederVictor.Set(0);
}

void Uptake::Periodic() { }
