#pragma once
#include <frc2/command/SubsystemBase.h>
#include <frc/AnalogGyro.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMSparkMax.h>

#include "Constants.h"

class Balance : public frc2::Subsystem {
    public:
        Balance();
        double getXAngle();
        double getYAngle();
        void Periodic() override;

    private: 
        frc::AnalogGyro m_gyro{gyroBalance::kGyroPort};
        double AngleX;
        double AngleY;
};