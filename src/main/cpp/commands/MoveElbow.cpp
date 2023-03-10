#include "commands/MoveElbow.h"
#include <frc/MathUtil.h>
#include <cmath>

MoveElbow::MoveElbow(Elbow* elbow, bool right) : m_elbow(elbow), isRight{right} {
    AddRequirements(elbow);
}

void MoveElbow::Initialize() {
    this->m_elbow->stop();
}

void MoveElbow::Execute() {
    // double angle = this->m_elbow->getRotationAngle();
    if(isRight) {
        this->m_elbow->setElbowMotor(0.3);
        // current_angle = angle;
    }
    else if(!isRight){
        this->m_elbow->setElbowMotor(-0.3);
        // current_angle = -angle;
    }
    // else {
    //     this->m_elbow->stop();
    // }
}

void MoveElbow::End(bool interrupted) {
    this->m_elbow->stop();
}

bool MoveElbow::IsFinished() {
    return false;
}