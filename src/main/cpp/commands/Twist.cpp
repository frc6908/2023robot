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
    double angle = this->m_wrist->getRotationAngle();
    if(isRight && current_angle <= 180.0) {
        if(angle >= 90.0) {
            this->m_wrist->stop();
        }
        else {
            this->m_wrist->setWristMotor(0.1);
        }
    }
    else if(!isRight && current_angle >= -180.0){
        if(angle >= 90.0) {
            this->m_wrist->stop();
        }
        else {
            this->m_wrist->setWristMotor(-0.1);
        }
    }
    else {
        this->m_wrist->stop();
    }
}

void Twist::End(bool interrupted) { 
    current_angle += (isRight ? 1 : -1) * this->m_wrist->getRotationAngle();
    this->m_wrist->resetEncoder();
    this->m_wrist->stop();
}

bool Twist::IsFinished() {
    return false;
}
