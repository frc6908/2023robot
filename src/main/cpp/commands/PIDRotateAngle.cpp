// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PIDRotateAngle.h"

PIDRotateAngle::PIDRotateAngle(Drivetrain* drivetrain, Limelight* limelight)
    : m_drivetrain{drivetrain}, m_limelight{limelight} {

    AddRequirements(drivetrain); 
    AddRequirements(limelight);
}

void PIDRotateAngle::Initialize() {
    stopAccumulator = 0;
    setpoint = 0;
    cumError = 0;
    previousError = 0;
    error = 0;
}

void PIDRotateAngle::Execute() {
    error = -this->m_limelight->getHorizontalOffset();
    cumError += error * drivetrain::kDT;
    double output = (kP * error) + (kD * (error - previousError) / drivetrain::kDT) + (kI * cumError);
    this->m_drivetrain->arcadeDrive(0, -output);
    previousError = error;
}

void PIDRotateAngle::End(bool interrupted) {
    this->m_drivetrain->stop();
}

bool PIDRotateAngle::IsFinished() {
    if (!this->m_limelight->hasValidTargetPose2d()) {
      return true;
    }
    
    if(std::abs(error)<=1) {
      stopAccumulator++;
    }
    else if(std::abs(error)>=1) {
      stopAccumulator = 0;
    }
    return stopAccumulator>=10;
}