#include "commands/ElevatorMotion.h"
#include <frc/MathUtil.h>
#include <cmath>

ElevatorMotion::ElevatorMotion(Elevator* elevator, bool dir) : m_elevator{elevator}, direction{dir} {
    AddRequirements(elevator);
}

void ElevatorMotion::Initialize() {
    this->m_elevator->stop();
}

void ElevatorMotion::Execute() {
    if(direction) {
        this->m_elevator->setElevatorMotors(0.7);
    }
    else {
        this->m_elevator->setElevatorMotors(-0.2);
    }
}

void ElevatorMotion::End(bool interrupted) {
    this->m_elevator->stop();
}

bool ElevatorMotion::IsFinished() {
    return false;
}