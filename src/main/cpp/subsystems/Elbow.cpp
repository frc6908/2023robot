#include "subsystems/Elbow.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Elbow::Elbow() {}

void Elbow::setElbowMotors(double speed) {
    elbowMotor.Set(speed);
}

void Elbow::stop() {
    elbowMotor.Set(0);
}

void Elbow::Periodic() {}