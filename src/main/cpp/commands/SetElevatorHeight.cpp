#include "commands/SetElevatorHeight.h"
#include <frc/MathUtil.h>
#include <cmath>

SetElevatorHeight::SetElevatorHeight(Elevator* elevator, bool dir) : m_elevator{elevator}, direction{dir} {
    AddRequirements(elevator);
}

void SetElevatorHeight::Initialize() {
    this->m_elevator->stop();
}

void SetElevatorHeight::Execute() {
    if(direction) {
        while(this->m_elevator->getElevatorDistance() > 30) {
            this->m_elevator->setElevatorMotors(0.2);
        }
        
    }
    else {
        while(this->m_elevator->getElevatorDistance() > 30) {
            this->m_elevator->setElevatorMotors(-0.2);
        }
    }
}

void SetElevatorHeight::End(bool interrupted) {
    this->m_elevator->stop();
}

bool SetElevatorHeight::IsFinished() {
    this->m_elevator->resetEncoder();
    return false;
}