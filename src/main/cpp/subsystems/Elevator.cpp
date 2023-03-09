#include "subsystems/Elevator.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Elevator::Elevator() {}

void Elevator::setElevatorMotors(double speed) {
    elevatorMotors.Set(speed);
} 

void Elevator::resetEncoder() {
    elevatorVenom.ResetPosition();
}

void Elevator::setCurrentHeight(double distance) {
    currentHeight = distance;
}

double Elevator::getCurrentHeight() {
    return currentHeight;
}

double Elevator::getEncoderPosition() {
    return elevatorVenom.GetPosition();
}

double Elevator::getElevatorDistance() {
    double angle = getEncoderPosition();
    return M_PI * elevator::kPulleyDiameter * angle / 10.71;  //idk what the 10.71 does, just copied from last year's code
}

void Elevator::stop() {
    elevatorMotors.Set(0);
}

void Elevator::Periodic() {}