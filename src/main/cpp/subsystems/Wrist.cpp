// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Wrist.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Wrist::Wrist() {}

void Wrist::setWristMotor(double speed) {
    wristMotor.Set(speed);
}

void Wrist::stop() {
    wristMotor.Set(0);
}

double Wrist::getRotationAngle() {
    return wristEncoder.GetRaw() * 360.0/ticks_per_revolution;
}

void Wrist::resetEncoder() {
    wristEncoder.Reset();
}

void Wrist::Periodic() {}