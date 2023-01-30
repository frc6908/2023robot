// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveAuton.h"

DriveAuton::DriveAuton(Drivetrain* drivetrain /*, Shooter* shooter, Uptake* uptake */ )
    : m_drivetrain{drivetrain} /* , m_shooter{shooter}, m_uptake{uptake} */ {

    AddRequirements(drivetrain); 
    /*
    AddRequirements(shooter);
    AddRequirements(uptake);
    */
}

void DriveAuton::Initialize() {
    t = 0;
    this->m_drivetrain->stop();
}

void DriveAuton::Execute() {
    /*
    if (t <= 500) {
        double tv = this->m_shooter->getTopVelocity();
        double bv = this->m_shooter->getBottomVelocity();

        if (this->m_shooter->withinTolerance(tv, topVelocity.value(), 3)) {
            // DO SOMETHING 
            this->m_uptake->setUptakeMotor(0.6);
            this->m_uptake->setTopFeederMotor(0.7);
        }

        this->m_shooter->getTPID()->SetSetpoint(this->topVelocity.value());
        this->m_shooter->getBPID()->SetSetpoint(this->bottomVelocity.value());

        units::voltage::volt_t ctop{this->m_shooter->getTPID()->Calculate(tv)};
        units::voltage::volt_t cbot{this->m_shooter->getBPID()->Calculate(bv)};

        this->m_shooter->setTopMotorVoltage(ctop + this->m_shooter->getTFF()->Calculate(topVelocity));
        this->m_shooter->setBottomMotorVoltage(cbot + this->m_shooter->getBFF()->Calculate(bottomVelocity));
    }
    */
    if (t > 500) {
        this->m_drivetrain->setDriveMotors(-0.4, -0.4);
    }
    t++;
}

void DriveAuton::End(bool interrupted) {
    this->m_drivetrain->stop();
    units::voltage::volt_t stopVoltage{0.0};
    /*
    this->m_shooter->setTopMotorVoltage(stopVoltage);
    this->m_shooter->setBottomMotorVoltage(stopVoltage);
    this->m_uptake->setTopFeederMotor(0);
    this->m_uptake->setUptakeMotor(0);
    */
}

bool DriveAuton::IsFinished() {
    return false;
}
