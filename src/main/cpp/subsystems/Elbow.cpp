#include "subsystems/Elbow.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Elbow::Elbow() {}

void Elbow::setElbowMotor(double speed) {
    elbowMotor.Set(speed);
}

void Elbow::stop() {
    elbowMotor.Set(0);
}

double Elbow::getRotationAngle() {
    return elbowEncoder.GetRaw() * 360.0/ticks_per_revolution;
}

void Elbow::resetEncoder() {
    elbowEncoder.Reset();
}

void Elbow::Periodic() {}