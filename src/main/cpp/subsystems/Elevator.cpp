#include "subsystems/Elevator.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Elevator::Elevator() {}

void Elevator::setElevatorMotors(double speed) {
    elevatorMotors.Set(speed);
} 

void Elevator::stop() {
    elevatorMotors.Set(0);
}

void Elevator::Periodic() {}