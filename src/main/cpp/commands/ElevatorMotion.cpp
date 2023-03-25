#include "commands/ElevatorMotion.h"
#include <frc/MathUtil.h>
#include <cmath>

ElevatorMotion::ElevatorMotion(Elevator* elevator, bool dir, double thr) : m_elevator{elevator}, direction{dir}, throttle {(thr+1.1)/2} {
    AddRequirements(elevator);
}

void ElevatorMotion::Initialize() {
    this->m_elevator->stop();
    this->m_elevator->resetEncoder();
}

void ElevatorMotion::Execute() {
    if(direction) {
        this->m_elevator->setElevatorMotors(throttle);
    }
    else {
        this->m_elevator->setElevatorMotors(-throttle);
    }
}

void ElevatorMotion::End(bool interrupted) {
    this->m_elevator->stop();
}

bool ElevatorMotion::IsFinished() {
    this->m_elevator->setCurrentHeight(this->m_elevator->getCurrentHeight() + this->m_elevator->getElevatorDistance());
    return false;
}
