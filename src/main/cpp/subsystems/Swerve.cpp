#include "subsystems/Swerve.h"


Swerve::Swerve() {
    // initialize stuff
}

void Swerve::swerveDrive(double x, double y, double z) {
    frc::ChassisSpeeds speed = frc::ChassisSpeeds::FromFieldRelativeSpeeds(units::meters_per_second_t(x), units::meters_per_second_t(y), z, gyro.GetRotation2d());
    auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speed);
    auto flOptimized = frc::SwerveModuleState::Optimize(fl, units::radian_t(front_left.getRotate()));
    auto frOptimized = frc::SwerveModuleState::Optimize(fr, units::radian_t(front_right.getRotate()));
    auto blOptimized = frc::SwerveModuleState::Optimize(bl, units::radian_t(back_left.getRotate()));
    auto brOptimized = frc::SwerveModuleState::Optimize(br, units::radian_t(back_right.getRotate()));
    front_left.setDesiredState((double)flOptimized.speed, (double)flOptimized.angle.Radians());
    front_right.setDesiredState((double)frOptimized.speed, (double)frOptimized.angle.Radians());
    back_left.setDesiredState((double)blOptimized.speed, (double)blOptimized.angle.Radians());
    back_right.setDesiredState((double)brOptimized.speed, (double)brOptimized.angle.Radians());
}

void Swerve::Periodic() {}