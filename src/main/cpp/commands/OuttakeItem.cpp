#include "commands/OuttakeItem.h"
#include <frc/MathUtil.h>
#include <cmath>

OuttakeItem::OuttakeItem(Intake* intake) : m_intake{intake} {}

void OuttakeItem::Initialize() {
    this->m_intake->stop();
}

void OuttakeItem::Execute() {
    this->m_intake->setIntakeMotors(-0.8);
}

void OuttakeItem::End(bool interrupted) {
    this->m_intake->stop();
}

bool OuttakeItem::IsFinished() {
    return false;
}