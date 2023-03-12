#include "commands/Extend.h"
#include <frc/MathUtil.h>
#include <cmath>

Extend::Extend(Arm* arm, bool ext) : m_arm{arm}, isExtend{ext} {
    AddRequirements(arm);    
}

void Extend::Initialize() {
    this->m_arm->stop();
}

void Extend::Execute() {
    if(isExtend) {
        this->m_arm->setTelescopeMotor(0.5);
    }
    else {
        this->m_arm->setTelescopeMotor(-0.5);
    }
}

void Extend::End(bool interrupted) {
    this->m_arm->stop();
}

bool Extend::IsFinished() {
    return false;
}