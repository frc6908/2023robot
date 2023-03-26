// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/BottomAuton.h"

BottomAuton::BottomAuton(Drivetrain* drivetrain) : m_drivetrain{drivetrain} {
    AddRequirements(drivetrain); 
}

void BottomAuton::Initialize() {
    t = 0;
    this->m_drivetrain->stop();
}

void BottomAuton::Execute() {
    if(t <= 25) {
        this->m_drivetrain->setDriveMotors(-0.6, -0.6);
    }
    else if(t <= 135) {
        this->m_drivetrain->setDriveMotors(0.4, 0.4);
    }
    else {
        this->m_drivetrain->setDriveMotors(0, 0);
    }
    t++;
}

void BottomAuton::End(bool interrupted) {
    this->m_drivetrain->stop();
}

bool BottomAuton::IsFinished() {
    return false;
}
