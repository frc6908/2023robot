// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"

Intake::Intake() {
  // Implementation of subsystem constructor goes here.
}


void Intake::setIntakeMotor(double intakeSpeed) {
  IntakeVictor.Set(intakeSpeed);
}

void Intake::setBottomFeederMotor(double bottomFeederSpeed) {
  BottomFeederVictor.Set(bottomFeederSpeed);
}

void Intake::stopIntake() {
  IntakeVictor.Set(0);
}

void Intake::stopBottomFeeder() {
  BottomFeederVictor.Set(0);
}

void Intake::Periodic() { }
