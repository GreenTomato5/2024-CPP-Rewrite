#ifndef SHOOTER_H
#define SHOOTER_H

#include "../../lib/include/subsystem/Subsystem.h"
#include <string>
#include <iostream>

class Shooter : public Subsystem {
 public:
     explicit Shooter();
     void Periodic() override;
     void SetSpeed(double speed);
     void Stop();
 private:
    enum class ShooterState {
        OFF,
        ON
    };
    ShooterState state;
    double speedPoint;
    std::string stateString;
};

#endif // SHOOTER_H

