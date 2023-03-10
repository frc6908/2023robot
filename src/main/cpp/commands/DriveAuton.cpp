// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveAuton.h"

DriveAuton::DriveAuton(Drivetrain* drivetrain) : m_drivetrain{drivetrain} {
    AddRequirements(drivetrain); 
}

void DriveAuton::Initialize() {
    t = 0;
    cumError = 0;
    prevError = 0;
    error = 0;
    this->m_drivetrain->stop();
}

void DriveAuton::Execute() {
    if(t <= 750) {
        if(gyromode) {
            error = this -> m_drivetrain -> getPitchAsAngle();
            cumError = error * drivetrain::kDT;
            double output = (kP * error) + (kD * (error - prevError) / drivetrain::kDT) + (kI * cumError);
            this->m_drivetrain->setDriveMotors(output, output);
            prevError = error;
        }   
        else {
            this->m_drivetrain->setDriveMotors(-0.4, -0.4);
            double angle = this->m_drivetrain->getPitchAsAngle();
            if(angle >= 6 || angle <= -6) {
                gyromode = true;
            }
        }
    }
    else {
        this->m_drivetrain->setDriveMotors(0, 0);
    }
    t++;
}

void DriveAuton::End(bool interrupted) {
    this->m_drivetrain->stop();
    /*
    this->m_shooter->setTopMotorVoltage(stopVoltage);
    this->m_shooter->setBottomMotorVoltage(stopVoltage);
    this->m_uptake->setTopFeederMotor(0);
    this->m_uptake->setUptakeMotor(0);
    */
}

bool DriveAuton::IsFinished() {
    return false;
}
