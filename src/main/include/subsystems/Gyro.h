#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"

class Gyro : public frc2::CommandHelper<frc2::CommandBase, Gyro> {
    public:
        Gyro(Drivetrain*);
        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;
    private:
        Drivetrain* m_drivetrain;
};