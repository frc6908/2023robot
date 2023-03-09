// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"

Intake::Intake() {}

void Intake::setIntakeMotors(double intakeSpeed) {
  IntakeTalon1.Set(intakeSpeed);
  IntakeTalon2.Set(-intakeSpeed);
}

void Intake::stop() {
  IntakeTalon1.Set(0);
  IntakeTalon2.Set(1);
}

void Intake::Periodic() {}
void Intake::SimulationPeriodic() {}
