#include "commands/SetElevatorHeight.h"
#include <frc/MathUtil.h>
#include <cmath>

SetElevatorHeight::SetElevatorHeight(Elevator* elevator, int sta) : m_elevator{elevator}, stage{sta}  {
    AddRequirements(elevator);
}

void SetElevatorHeight::Initialize() {
    this->m_elevator->stop();
    this->m_elevator->resetEncoder();
    if(stage == 0) {
        if(this->m_elevator->getCurrentHeight() >= lowStageHeight) {
            goingUp = false;
        }
        else {
            goingUp = true;
        }
    }
    else if(stage == 1) {
        if(this->m_elevator->getCurrentHeight() >= midStageHeight) {
           goingUp = false; 
        }
        else {
            goingUp = true;
        }
    }
    else if(stage == 2) {
        if(this->m_elevator->getCurrentHeight() >= highStageHeight) {
            goingUp = false;
        }
        else {
            goingUp = true;
        }
    }
    else {
        if(this->m_elevator->getCurrentHeight() >= playerHeight) {
            goingUp = false;
        }    
        else {
            goingUp = true;
        }
    }
}

void SetElevatorHeight::Execute() {
    //bottom height
    if(stage == 0) {
        if (this->m_elevator->getCurrentHeight() + this->m_elevator->getElevatorDistance() > lowStageHeight && !goingUp) {
            this->m_elevator->setElevatorMotors(-0.2);
        }
        else {
            this->m_elevator->setElevatorMotors(0);
        }
    }

    //mid stage height
    else if (stage == 1){
        if (this->m_elevator->getCurrentHeight() + this->m_elevator->getElevatorDistance() > midStageHeight && !goingUp) {
            this->m_elevator->setElevatorMotors(-0.2);
        }
        else if (this->m_elevator->getCurrentHeight() + this->m_elevator->getElevatorDistance() < midStageHeight && goingUp) {
            this->m_elevator->setElevatorMotors(0.2);
        }
        else {
            this->m_elevator->setElevatorMotors(0);
        }
    }

    //high stage height
    else if (stage == 2){
        if (this->m_elevator->getCurrentHeight() + this->m_elevator->getElevatorDistance() < highStageHeight && goingUp) {
            this->m_elevator->setElevatorMotors(0.2);
        }
        else {
            this->m_elevator->setElevatorMotors(0);
        }
    }

    //player height
    else if (stage == 3){
        if (this->m_elevator->getCurrentHeight() + this->m_elevator->getElevatorDistance() > playerHeight && !goingUp) {
            this->m_elevator->setElevatorMotors(-0.2);
        }
        else if (this->m_elevator->getCurrentHeight() + this->m_elevator->getElevatorDistance() < playerHeight && goingUp) {
            this->m_elevator->setElevatorMotors(0.2);
        }
        else {
            this->m_elevator->setElevatorMotors(0);
        }
    }
}

void SetElevatorHeight::End(bool interrupted) {
    this->m_elevator->stop();
}

bool SetElevatorHeight::IsFinished() {    
    if (stage == 0) {
        this->m_elevator->setCurrentHeight(lowStageHeight);
    }
    else if (stage == 1) {
        this->m_elevator->setCurrentHeight(midStageHeight);
    }
    else if (stage == 2) {
        this->m_elevator->setCurrentHeight(highStageHeight);
    }
    else if (stage == 3) {
        this->m_elevator->setCurrentHeight(playerHeight);
    }
    return true;
}