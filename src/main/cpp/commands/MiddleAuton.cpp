// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/MiddleAuton.h"

MiddleAuton::MiddleAuton(Drivetrain* drivetrain, Elbow* elbow) : m_drivetrain{drivetrain}, m_elbow{elbow} {
    AddRequirements(drivetrain); 
}

void MiddleAuton::Initialize() {
    t = 0;
    this->m_drivetrain->stop();
}

void MiddleAuton::Execute() {
    if(t <= 30) {
        this->m_elbow->setElbowMotor(1);
    }
    else if(t <= 130) {
        this->m_drivetrain->setDriveMotors(0.4, 0.4);
    }
    else {
        this->m_drivetrain->setDriveMotors(0, 0);
    }
    t++;
}

void MiddleAuton::End(bool interrupted) {
    this->m_drivetrain->stop();
}

bool MiddleAuton::IsFinished() {
    return false;
}
