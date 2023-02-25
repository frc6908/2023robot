// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"

Intake::Intake() {
  // Implementation of subsystem constructor goes here.
}


void Intake::setIntakeMotor1(double intakeSpeed1) {
  IntakeTalon1.Set(intakeSpeed1);
}

void Intake::setIntakeMotor2(double intakeSpeed2) {
  IntakeTalon2.Set(intakeSpeed2);
}

void Intake::stopIntake1() {
  IntakeTalon1.Set(0);
}

void Intake::stopIntake2() {
  IntakeTalon2.Set(0);
}

void Intake::Periodic() { }
