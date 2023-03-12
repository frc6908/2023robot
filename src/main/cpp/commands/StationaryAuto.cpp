// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/StationaryAuto.h"

StationaryAuto::StationaryAuto(Drivetrain* drivetrain) : m_drivetrain{drivetrain} {
    AddRequirements(drivetrain); 
}

void StationaryAuto::Initialize() {
    t = 0;
    this->m_drivetrain->stop();
}

void StationaryAuto::Execute() {
    if(t <= 750) {
        this->m_drivetrain->setDriveMotors(0, 0);
    }
    else {
        this->m_drivetrain->setDriveMotors(0, 0);
    }
    t++;
}

void StationaryAuto::End(bool interrupted) {
    this->m_drivetrain->stop();
    /*
    this->m_shooter->setTopMotorVoltage(stopVoltage);
    this->m_shooter->setBottomMotorVoltage(stopVoltage);
    this->m_uptake->setTopFeederMotor(0);
    this->m_uptake->setUptakeMotor(0);
    */
}

bool StationaryAuto::IsFinished() {
    return false;
}
