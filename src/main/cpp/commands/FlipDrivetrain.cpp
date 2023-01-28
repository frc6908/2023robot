// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/FlipDrivetrain.h"

FlipDrivetrain::FlipDrivetrain(Drivetrain* drivetrain)
    : m_drivetrain{drivetrain} {

    AddRequirements(drivetrain); 
}

void FlipDrivetrain::Initialize() {
    this->m_drivetrain->flipDT();
}

void FlipDrivetrain::Execute() { }

void FlipDrivetrain::End(bool interrupted) { }

bool FlipDrivetrain::IsFinished() {
    return true;
}
