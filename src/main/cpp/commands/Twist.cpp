// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Twist.h"

Twist::Twist(Wrist* wrist, bool right) : m_wrist{wrist}, isRight{right} {
    AddRequirements(wrist); 
}

void Twist::Initialize() {
    this->m_wrist->stop();
}

void Twist::Execute() {
    if(isRight) {
        this->m_wrist->setWristMotor(0.3);
    }
    else {
        this->m_wrist->setWristMotor(-0.3);
    }
}

void Twist::End(bool interrupted) { 
    this->m_wrist->stop();
}

bool Twist::IsFinished() {
    return false;
}
