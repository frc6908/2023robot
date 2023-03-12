// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"

Intake::Intake() {}

void Intake::setIntakeMotors(double intakeSpeed) {
  IntakeMotor1.Set(intakeSpeed);
  IntakeMotor2.Set(-intakeSpeed);
}

void Intake::stop() {
  IntakeVictor1.Set(0);
  IntakeVictor2.Set(0);
}

void Intake::Periodic() {}
void Intake::SimulationPeriodic() {}
