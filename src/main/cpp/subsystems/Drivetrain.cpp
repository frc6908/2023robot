// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

Drivetrain::Drivetrain() {
    rightMotors.SetInverted(1); // inverts the right drive motors
    resetGyro();
}

void Drivetrain::setDriveMotors(double left, double right) {
    //tab.Add("Left Motor", left);
    //tab.Add("Right Motor", right);
    
    if (flipped) {
        leftMotors.Set(-right);
        rightMotors.Set(-left);
    } else {
        leftMotors.Set(left);
        rightMotors.Set(right);
    }
    //NetworkTableEntry testTab = Shuffleboard.getTab("Test").add("Pi", 3.14);
}

void Drivetrain::arcadeDrive(double throttle, double turn) {
    setDriveMotors(throttle + turn, throttle - turn);
}

void Drivetrain::stop() {
    leftMotors.Set(0);
    rightMotors.Set(0);
}

void Drivetrain::flipDT() {
    flipped = !flipped;
}

frc::Rotation2d Drivetrain::getHeading() {
    units::degree_t deg{-gyro.GetAngle()};
    return frc::Rotation2d(deg);
}

double Drivetrain::getHeadingAsAngle() {
    return getHeading().Degrees().value();
}

void Drivetrain::resetEncoders() {
    leftDriveVenom.ResetPosition();
    rightDriveVenom.ResetPosition();
}

double Drivetrain::getLeftEncoderDistance() {
    return leftDriveVenom.GetPosition();
}

double Drivetrain::getRightEncoderDistance() {
    return rightDriveVenom.GetPosition();
}

double Drivetrain::venomTicksToInches(double revolutions) {
    return M_PI * drivetrain::kWheelDiameter * revolutions / 10.71;
}

void Drivetrain::resetGyro() {
    gyro.Reset();
}
// This method will be called once per scheduler run
void Drivetrain::Periodic() {}
