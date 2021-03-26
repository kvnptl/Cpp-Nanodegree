#include <assert.h>
#include <cmath>

// TODO: Define PI
#define PI 3.14

// TODO: Declare abstract class VehicleModel
class VehicleModel
{
public:
    // TODO: Declare virtual function Move()
    virtual void Move(double v, double t) = 0;
};

// TODO: Derive class ParticleModel from VehicleModel
class ParticleModel : public VehicleModel
{
public:
    // TODO: Define x, y, and theta
    double theta;
    double x;
    double y;

    // TODO: Override the Move() function
    void Move(double v, double t) override
    {
        theta = theta + t;
        x = x + v * cos(theta);
        y = y + v * cos(theta);
    }
};

// TODO: Derive class BicycleModel from ParticleModel
class BicycleModel : public ParticleModel
{
public:
    // TODO: Override the Move() function
    void Move(double v, double t) override
    {
        theta = theta + (v / (L * tan(t)));
        x = x + v * cos(theta);
        y = y + v * cos(theta);
    }
    // TODO: Define L
    int L{1};
};

// TODO: Pass the tests
int main()
{
    // Test function overriding
    ParticleModel particle;
    BicycleModel bicycle;
    particle.Move(10, PI / 9);
    bicycle.Move(10, PI / 9);
    assert(particle.x != bicycle.x);
    assert(particle.y != bicycle.y);
    assert(particle.theta != bicycle.theta);
}