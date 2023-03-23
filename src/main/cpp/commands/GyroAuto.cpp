// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GyroAuto.h"

GyroAuto::GyroAuto(Drivetrain* drivetrain) : m_drivetrain{drivetrain} {
    AddRequirements(drivetrain); 
}

void GyroAuto::Initialize() {
    t = 0;
    gyromode = false;
    this->m_drivetrain->stop();
}

void GyroAuto::Execute() {
    if(t <= 750) {
        if(gyromode) {
            // when on top of the charging station
            if(fabs(this->m_drivetrain->getPitchAsAngle()) < 9) {
                this->m_drivetrain->setDriveMotors(0.0, 0.0);
            }
            else {
                this->m_drivetrain->setDriveMotors(-0.2, -0.2);
            }

        }    
        else {
            this->m_drivetrain->setDriveMotors(-0.4, -0.4);
            if(fabs(this -> m_drivetrain -> getPitchAsAngle()) > 30) {
                gyromode = true;
            }
        }
    }
    else {
        this->m_drivetrain->setDriveMotors(0, 0);
    }
    t++;
}

void GyroAuto::End(bool interrupted) {
    this->m_drivetrain->stop();
    /*
    this->m_shooter->setTopMotorVoltage(stopVoltage);
    this->m_shooter->setBottomMotorVoltage(stopVoltage);
    this->m_uptake->setTopFeederMotor(0);
    this->m_uptake->setUptakeMotor(0);
    */
}

bool GyroAuto::IsFinished() {
    return false;
}
