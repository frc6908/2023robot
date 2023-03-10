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
        this->m_elevator->setElevatorMotors(1);
    }
    else {
        this->m_elevator->setElevatorMotors(-1);
    }
}

void ElevatorMotion::End(bool interrupted) {
    this->m_elevator->stop();
}

bool ElevatorMotion::IsFinished() {
    return false;
}