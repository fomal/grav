#ifndef BODYCLASS_H
#define BODYCLASS_H
#include <vector>

class BodyClass : public BodyClass
{
    public:
        BodyClass(float initial_x, float initial_y, float initial_xv, float initial_yv, float initial_mass);
        ~BodyClass();
        void ChangePos(float new_x, float new_y);
        void AddVel(float new_xv, float new_yv);
        std::pair<float, float> GetPos();
        float pos_x, pos_y, xv, yv, mass;
};
#endif // BODYCLASS_H
void simulate(std::vector<BodyClass>& bodies);
float distance(std::pair<float, float> body1, std::pair<float, float> body2);
float distance_soft(std::pair<float, float> body1, std::pair<float, float> body2);
