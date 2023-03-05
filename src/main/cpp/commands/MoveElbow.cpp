#include "commands/MoveElbow.h"
#include <frc/MathUtil.h>
#include <cmath>

MoveElbow::MoveElbow(Elbow* elbow) : m_elbow(elbow) {
    AddRequirements(elbow);
}

void MoveElbow::Initialize() {
    this->m_elbow->stop();
}

void MoveElbow::Execute() {
    
}

void MoveElbow::End(bool interrupted) {
    this->m_elbow->stop();
}

bool MoveElbow::IsFinished() {
    return false;
}