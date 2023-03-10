#include "subsystems/Arm.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Arm::Arm() {}

void Arm::setTelescopeMotor(double speed){
    telescopeMotor.Set(speed);
} 

void Arm::stop() {
    telescopeMotor.Set(0);
}

void Arm::Periodic() {}
