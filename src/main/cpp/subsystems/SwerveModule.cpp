// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SwerveModule.h"

SwerveModule::SwerveModule() {}

void SwerveModule::setDesiredState(double forwardSpeed, double rotateAngle) {
    // forwardSpeed move forward motor by forwardSpeed
    // rotateAngle PID to rotate to that angle
}

void SwerveModule::stop() {
    // Set drive motor to 0
}

double SwerveModule::getRotate() {
    // get current angle of rotateMotor
}

double SwerveModule::getForward() {
    // get current speed of driveMotor
}

void SwerveModule::resetEncoders() {
    // reset encoders
}

double SwerveModule::ticksToMeters() {
    // ticks to meters of neo
}

void SwerveModule::Periodic() {} 