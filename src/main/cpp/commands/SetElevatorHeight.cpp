#include "commands/SetElevatorHeight.h"
#include <frc/MathUtil.h>
#include <cmath>

SetElevatorHeight::SetElevatorHeight(Elevator* elevator, int sta, double thr) : m_elevator{elevator}, stage{sta}, throttle{(thr+1.1)/2} {
    AddRequirements(elevator);
}

void SetElevatorHeight::Initialize() {
    this->m_elevator->stop();
}

void SetElevatorHeight::Execute() {
    //bottom height
    if(stage == 0) {
        if (this->m_elevator->getCurrentHeight() > lowStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(this->m_elevator->getCurrentHeight()-lowStageHeight)) {
                this->m_elevator->setElevatorMotors(-0.2);
            }
        }
    }

    //mid stage height
    else if (stage == 1){
        if (this->m_elevator->getCurrentHeight() > midStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(this->m_elevator->getCurrentHeight()-midStageHeight)) {
                this->m_elevator->setElevatorMotors(-0.2);
            }
        }
        if (this->m_elevator->getCurrentHeight() < lowStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(this->m_elevator->getCurrentHeight()-midStageHeight)) {
                this->m_elevator->setElevatorMotors(0.2);
            }
        }
    }

    //high stage height
    else if (stage == 2){
        if (this->m_elevator->getCurrentHeight() < highStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(this->m_elevator->getCurrentHeight()-highStageHeight)) {
                this->m_elevator->setElevatorMotors(0.2);
            }
        }
    }

    //player height
    else if (stage == 3){
        if (this->m_elevator->getCurrentHeight() > playerHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(this->m_elevator->getCurrentHeight()-playerHeight)) {
                this->m_elevator->setElevatorMotors(-0.2);
            }
        }
        if (this->m_elevator->getCurrentHeight() < lowStageHeight) {
            while(this->m_elevator->getElevatorDistance() < abs(this->m_elevator->getCurrentHeight()-playerHeight)) {
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
        this->m_elevator->setCurrentHeight(lowStageHeight);
    }
    else if (stage == 1) {
<<<<<<< HEAD
        this->m_elevator->setCurrentHeight(midStageHeight);
    }
    else if (stage == 2) {
        this->m_elevator->setCurrentHeight(highStageHeight);
    }
    else if (stage == 3) {
        this->m_elevator->setCurrentHeight(playerHeight);
=======
        currentHeight = midStageHeight;
    }
    else if (stage == 2) {
        currentHeight = highStageHeight;
    }
    else if (stage == 3) {
        currentHeight = playerHeight;
>>>>>>> 4dfe1e5de75e51105a609fc49055630b3b197d34
    }
    return true;
}