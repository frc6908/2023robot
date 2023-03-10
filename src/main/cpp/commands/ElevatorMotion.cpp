#include "commands/ElevatorMotion.h"
#include <frc/MathUtil.h>
#include <cmath>

ElevatorMotion::ElevatorMotion(Elevator* elevator, bool dir, double thr) : m_elevator{elevator}, direction{dir}, throttle {(thr+1.1)/2} {
    AddRequirements(elevator);
}

void ElevatorMotion::Initialize() {
    this->m_elevator->stop();
}

void ElevatorMotion::Execute() {
    if(direction) {
<<<<<<< HEAD
        this->m_elevator->setElevatorMotors(throttle);
    }
    else {
        this->m_elevator->setElevatorMotors(-throttle);
=======
        this->m_elevator->setElevatorMotors(1);
    }
    else {
        this->m_elevator->setElevatorMotors(-1);
>>>>>>> 4dfe1e5de75e51105a609fc49055630b3b197d34
    }
}

void ElevatorMotion::End(bool interrupted) {
    this->m_elevator->stop();
}

bool ElevatorMotion::IsFinished() {
    if (direction) {
         this->m_elevator->setCurrentHeight(this->m_elevator->getCurrentHeight() + 
                                            this->m_elevator->getElevatorDistance());
    }
    else {
        this->m_elevator->setCurrentHeight(this->m_elevator->getCurrentHeight() - 
                                           this->m_elevator->getElevatorDistance());
    }
    return false;
}
