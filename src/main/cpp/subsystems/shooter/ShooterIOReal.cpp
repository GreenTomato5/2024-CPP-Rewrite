#include "subsystems/shooter/ShooterIO.h"

#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/motorcontrol/PWMTalonFX.h>
#include <frc/controller/BangBangController.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/Encoder.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <units/units.h>

class ShooterIOReal : protected ShooterIO {
 public:
  ShooterIOReal()  {
    leftMotor.SetInverted(true);
    rightMotor.SetInverted(false);

    leftMotor.SetControl(ctre::phoenix6::controls::Follower{1, true});
  };
  
  void SetSpeed(double speedRPS) override{
    rightMotor.Set(controller.Calculate(rightMotor.GetVelocity().GetValueAsDouble(), speedRPS));
  };

  void Stop() override {
    rightMotor.Set(0);
  };

  void configureFF(double kS, double kV, double kA) override {
    feedforward = frc::SimpleMotorFeedforward<units::rotation_per_second>(kS_V, kV_V / 1_rpm);
  };

  private:
    frc::BangBangController controller;
    ctre::phoenix6::hardware::TalonFX rightMotor{1};
    ctre::phoenix6::hardware::TalonFX leftMotor{2};
    frc::SimpleMotorFeedforward<units::rotation_per_second> feedforward{0.1_V, 0.2_V / 1_rpm};
};
