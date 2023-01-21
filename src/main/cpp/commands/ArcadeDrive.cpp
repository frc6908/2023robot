// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ArcadeDrive.h"
#include <frc/MathUtil.h>
#include <cmath>

double normalize(double min, double max, double a, double b, double x) {
  return (((b-a) * (x-min)) / (max-min)) + a;
}

ArcadeDrive::ArcadeDrive(Drivetrain* drivetrain, std::function<double()> throttle, std::function<double()> turn,   std::function<double()> acceleration) : 
  m_drivetrain{drivetrain}, m_acceleration{std::move(acceleration)}, m_turn{std::move(turn)}, m_throttle{std::move(throttle)} {
  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(drivetrain);
}

