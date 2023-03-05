#pragma once

#include <cmath>

#include <frc2/command/SubsystemBase.h>

#include <CANVenom.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <frc/SPI.h>
#include <AHRS.h>

#include <frc/geometry/Rotation2d.h>

#include <frc/drive/DifferentialDrive.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include "Constants.h"

class Elevator : public frc2::SubsystemBase {
    public:
        Elevator();

        void setElevatorMotors(double);

        void resetEncoder();

        double getEncoderPosition();

        double getElevatorDistance();

        void stop();

        void Periodic() override;

    private:
        ctre::phoenix::motorcontrol::can::WPI_TalonSRX elevatorTalon{elevator::kElevatorTalonPort};
        frc::CANVenom elevatorVenom{elevator::kElevatorVenomPort};

        frc::MotorControllerGroup elevatorMotors{elevatorTalon, elevatorVenom};
};