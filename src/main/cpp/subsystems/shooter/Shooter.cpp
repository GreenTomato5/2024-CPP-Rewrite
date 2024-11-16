#include "subsystems/shooter/Shooter.h"

Shooter::Shooter()
    : state(ShooterState::OFF), speedPoint(0.0), stateString("OFF") {}


void periodic() {
    std::cout << "ShooterSubsystem::Periodic" << std::endl;
}

void main() {
    
}