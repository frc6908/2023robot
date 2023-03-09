#include "commands/SetElevatorHeight.h"
#include <frc/MathUtil.h>
#include <cmath>

SetElevatorHeight::SetElevatorHeight(Elevator* elevator, int sta) : m_elevator{elevator}, stage{sta} {
    AddRequirements(elevator);
}

void SetElevatorHeight::Initialize() {
    this->m_elevator->stop();
}

void SetElevatorHeight::Execute() {
    //bottom height
    if(stage == 0) {
        if (currentHeight > lowStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(currentHeight-lowStageHeight)) {
                this->m_elevator->setElevatorMotors(-0.2);
            }
        }
    }

    //mid stage height
    else if (stage == 1){
        if (currentHeight > midStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(currentHeight-midStageHeight)) {
                this->m_elevator->setElevatorMotors(-0.2);
            }
        }
        if (currentHeight < lowStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(currentHeight-midStageHeight)) {
                this->m_elevator->setElevatorMotors(0.2);
            }
        }
    }

    //high stage height
    else if (stage == 2){
        if (currentHeight < highStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(currentHeight-highStageHeight)) {
                this->m_elevator->setElevatorMotors(0.2);
            }
        }
    }

    //player height
    else if (stage == 3){
        if (currentHeight > playerHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(currentHeight-playerHeight)) {
                this->m_elevator->setElevatorMotors(-0.2);
            }
        }
        if (currentHeight < lowStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(currentHeight-playerHeight)) {
                this->m_elevator->setElevatorMotors(0.2);
            }
        }
    }
}

void SetElevatorHeight::End(bool interrupted) {
    this->m_elevator->stop();
}

bool SetElevatorHeight::IsFinished() {
    this->m_elevator->resetEncoder();
    
    if (stage == 0) {
        currentHeight = lowStageHeight;
    }
    else if (stage == 1) {
        currentHeight = midStageHeight;
    }
    else if (stage == 2) {
        currentHeight = highStageHeight;
    }
    else if (stage == 3) {
        currentHeight = playerHeight;
    }
    
    return true;
}