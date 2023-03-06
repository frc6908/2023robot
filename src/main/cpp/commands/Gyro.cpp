#include "commands/Gyro.h"
#include <frc/MathUtil.h>
#include <cmath>

Gyro::Gyro(Drivetrain* drivetrain) : m_drivetrain{drivetrain} {
    AddRequirements(drivetrain);
}

void Gyro::Initialize() {
  cumError = 0;
  prevError = 0;
  error = 0;
}

void Gyro::Execute() { 
  double error = this -> m_drivetrain -> getPitchAsAngle();
  error = error * drivetrain::kDT;
  cumError = error * drivetrain::kDT;
  double output = (kP * error) + (kD * (error - prevError) / drivetrain::kDT) + (kI * cumError);
  this->m_drivetrain->arcadeDrive(0, output);
  prevError = error;
} 

// Called once the command ends or is interrupted.
void Gyro::End(bool interrupted) {
  this->m_drivetrain->stop();
}

// Returns true when the command should end.
bool Gyro::IsFinished() {
  return false;
}