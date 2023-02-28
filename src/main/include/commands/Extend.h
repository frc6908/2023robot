#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/AnalogGyro.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>

#include "Constants.h"

#include "subsystems/Arm.h"

class Extend : public frc2::CommandHelper<frc2::CommandBase, Extend> {
    public:
        Extend(Arm*, int);
        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;
    private:
        Arm* m_arm;
        int target_mode;
        int t;
};