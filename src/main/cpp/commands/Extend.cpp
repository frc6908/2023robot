#include "commands/Extend.h"
#include <frc/MathUtil.h>
#include <cmath>

Extend::Extend(Arm* arm, int m) : m_arm{arm}, target_mode{m} {
    AddRequirements(arm);    
}

void Extend::Initialize() {
    t = 0;
    this->m_arm->stop();
}

void Extend::Execute() {
    if(t <= 100) {
        this->m_arm->extension(target_mode);
    }
    else {
        this->m_arm->stop();
    }
    t++;
}

void Extend::End(bool interrupted) {
    this->m_arm->stop();
}

bool Extend::IsFinished() {
    return false;
}