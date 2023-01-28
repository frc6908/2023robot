// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Limelight.h"

Limelight::Limelight() {
  // Implementation of subsystem constructor goes here.
}

double Limelight::getHorizontalOffset() {
  return limelightTable->GetNumber("tx", 6908.0);
}

double Limelight::getVerticalOffset() {
  return limelightTable->GetNumber("ty", 6908.0);
}

double Limelight::getArea() {
  return limelightTable->GetNumber("ta", 6908.0);
}

double Limelight::getSkew() {
  return limelightTable->GetNumber("ts", 6908.0);
}

double Limelight::getDistance() {
  return (limelight::kTargetHeight - limelight::kCameraHeight) / ( tan( (M_PI / 180) * (limelight::kCameraAngle + getVerticalOffset()) ) );
}

bool Limelight::hasValidTargetPose2d() {
  if (getArea() == 6908.0) {
    return false;
  }
  if (getDistance() == 6908.0) {
    return false;
  }
  if (getVerticalOffset() == 6908.0) {
    return false;
  }
  if (getHorizontalOffset() == 6908.0) {
    return false;
  }
  if (getSkew() == 6908.0) {
    return false;
  }
  return true;
}


void Limelight::Periodic() { }
