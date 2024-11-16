#ifndef SHOOTER_IO_H
#define SHOOTER_IO_H

#include <string>

class ShooterIO {
public:
    virtual ~ShooterIO() = default;

    virtual void SetSpeed(double speed) = 0;
    virtual void Stop() = 0;
    virtual void configureFF(double kS, double kV, double kA) = 0;
};

#endif // SHOOTER_IO_H
