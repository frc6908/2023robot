#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/AnalogGyro.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>

#include "Constants.h"

#include "subsystems/Drivetrain.h"

class Gyro : public frc2::CommandHelper<frc2::CommandBase, Gyro> {
    public:
        Gyro(Drivetrain*);
        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;
    private:
        frc::AnalogGyro m_gyro{gyroBalance::kGyroPort};
        Drivetrain* m_drivetrain;
};