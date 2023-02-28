#include "subsystems/Arm.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Arm::Arm() {}

void Arm::setTelescopeMotor(double speed){
    telescopeMotor.Set(speed);
} 

void Arm::extension(int targetMode) {
    if(targetMode == 0) {
        if(currentMode == 0) {
            setTelescopeMotor(0);
        }
        else if(currentMode == 1) {
            setTelescopeMotor(-0.1);
        }
        else {
            setTelescopeMotor(-0.2);
        }
        currentMode = 0;
    }
    else if (targetMode == 1) {
        if(currentMode == 0) {
            setTelescopeMotor(0.1);
        }   
        else if(currentMode == 1) {
            setTelescopeMotor(0);
        }
        else {
            setTelescopeMotor(-0.1);
        }
        currentMode = 1;
    }
    else {
        if(currentMode == 0) {
            setTelescopeMotor(0.2);
        }
        else if(currentMode == 1) {
            setTelescopeMotor(0.1);
        }
        else {
            setTelescopeMotor(0);
        }
        currentMode = 2;
    }
}

void Arm::stop() {
    telescopeMotor.Set(0);
}

void Arm::Periodic() {}
