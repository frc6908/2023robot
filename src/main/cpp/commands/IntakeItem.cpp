#include "commands/IntakeItem.h"
#include <frc/MathUtil.h>
#include <cmath>

IntakeItem::IntakeItem(Intake* intake) : m_intake{intake} {}

void IntakeItem::Initialize() {
    this->m_intake->stop();
}

void IntakeItem::Execute() {
    this->m_intake->setIntakeMotors(-0.5);
}

void IntakeItem::End(bool interrupted) {
    this->m_intake->stop();
}

bool IntakeItem::IsFinished() {
    return false;
}