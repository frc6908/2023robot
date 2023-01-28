// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>
#include <rev/CANSparkMaxLowLevel.h>
#include <rev/SparkMaxRelativeEncoder.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"

#include <frc/controller/PIDController.h>
#include <frc/controller/SimpleMotorFeedforward.h>

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTableEntry.h>

class Shooter: public frc2::SubsystemBase {
 public:

  Shooter();

  void setBottomMotorVoltage(units::voltage::volt_t);

  void setTopMotorVoltage(units::voltage::volt_t);

  double getTopVelocity(void);

  double getBottomVelocity(void);

  frc::PIDController* getTPID(void);

  frc::PIDController* getBPID(void);

  frc::SimpleMotorFeedforward<units::meters>* getTFF(void);

  frc::SimpleMotorFeedforward<units::meters>* getBFF(void);

  void stopShooter(void);

  bool withinTolerance(double, double, double);


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  
  rev::CANSparkMax bottomSpark{shooter::kBottomSparkPort, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax topSpark{shooter::kTopSparkPort, rev::CANSparkMaxLowLevel::MotorType::kBrushless};

  rev::SparkMaxRelativeEncoder bottomEncoder = bottomSpark.GetEncoder();
  rev::SparkMaxRelativeEncoder topEncoder = topSpark.GetEncoder();

  frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("SmartDashboard");
  //frc::SmartDashboard::PutNumber("bottomVelocity", this->m_shooter->getBottomVelocity());

  nt::NetworkTableEntry tp = tab.Add("TopP", 0.0).GetEntry();
  nt::NetworkTableEntry ti = tab.Add("TopI", 0.0).GetEntry();
  nt::NetworkTableEntry td = tab.Add("TopD", 0.0).GetEntry();
  /*
  double tkP = 0.0075;
  double tkI = 0.01;
  double tkD = 0.005;
  */
  double tkP = tp.GetDouble(0.0);
  double tkI = ti.GetDouble(0.0);
  double tkD = td.GetDouble(0.0);

  units::volt_t tkS{0.0643};
  units::unit_t< units::compound_unit<units::volts, units::seconds, units::inverse<units::meters>> > tkV{0.128};
  units::unit_t< units::compound_unit<units::volts, units::seconds, units::seconds, units::inverse<units::meters>> > tkA{0.0205};

  nt::NetworkTableEntry bp = tab.Add("BottomP", 0.0).GetEntry();
  nt::NetworkTableEntry bi = tab.Add("BottomI", 0.0).GetEntry();
  nt::NetworkTableEntry bd = tab.Add("BottomD", 0.0).GetEntry();
  
  double bkP = bp.GetDouble(0.0);
  double bkI = bi.GetDouble(0.0);
  double bkD = bd.GetDouble(0.0);

  units::volt_t bkS{0.0496};
  units::unit_t< units::compound_unit<units::volts, units::seconds, units::inverse<units::meters>> > bkV{0.129};
  units::unit_t< units::compound_unit<units::volts, units::seconds, units::seconds, units::inverse<units::meters>> > bkA{0.0208};

  frc::PIDController tpid{tkP, tkI, tkD};
  frc::PIDController bpid{bkP, bkI, bkD};

  frc::SimpleMotorFeedforward<units::meters> tff{tkS, tkV, tkA};
  frc::SimpleMotorFeedforward<units::meters> bff{bkS, bkV, bkA};
};
