#include "commands/Gyro.h"
#include <frc/MathUtil.h>
#include <cmath>

Gyro::Gyro(Drivetrain* drivetrain) : m_drivetrain{drivetrain} {
    AddRequirements(drivetrain);
}

void Gyro::Initialize() {
  this->m_drivetrain->stop();
}

// Called repeatedly when this Command is scheduled to run
void Gyro::Execute() { 
  // basically find pitch angle, and drive backwards/forwards while pitch angle is incorrect.
  double pitchAngleDegrees = this -> m_drivetrain -> getPitchAsAngle();
  // move backward (i think)
  if(pitchAngleDegrees < 0) {
    // do something to move backward
    // these speeds are just placeholders currently
    this->m_drivetrain->setDriveMotors(-1.0, -1.0);
  } 
  // move forwards
  else if(pitchAngleDegrees > 0) {
    // do something to move forwards
    this->m_drivetrain->setDriveMotors(1.0, 1.0);
  }
} 

// Called once the command ends or is interrupted.
void Gyro::End(bool interrupted) {
  this->m_drivetrain->stop();
}

// Returns true when the command should end.
bool Gyro::IsFinished() {
  return false;
}