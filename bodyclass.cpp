#include "bodyclass.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

class BodyClass : public BodyClass
{
    public:
        BodyClass(float initial_x, float initial_y, float initial_xv, float initial_yv, float initial_mass);
        ~BodyClass();
        void ChangePos(float, float);
        void AddVel(float, float);
        pair<float, float> GetPos();
        float pos_x, pos_y, xv, yv, mass;
};
BodyClass::BodyClass(float initial_x, float initial_y, float initial_xv, float initial_yv, float initial_mass)
{
    //void changepos(int, int);
    this->pos_x = initial_x;
    this->pos_y = initial_y;
    this->xv = initial_xv;
    this->yv = initial_yv;
    this->mass = initial_mass;
    cout << "constructed a body at " << this->pos_x << "," << this->pos_y << endl;
}
void BodyClass::ChangePos(float new_x, float new_y)
{
    this->pos_x += new_x;
    this->pos_y += new_y;
}
void BodyClass::AddVel(float new_xv, float new_yv)
{
    this->xv += new_xv;
    this->yv += new_yv;
}
pair<float, float> BodyClass::GetPos()
{
    return make_pair(this->pos_x, this->pos_y);
}
float distance(pair<float, float> body1, pair<float, float> body2)
{
    return sqrt(pow((body1.first-body2.first),2) + pow((body1.second-body2.second),2));
}
float distance_soft(pair<float, float> body1, pair<float, float> body2)
{
    return (sqrt(pow((body1.first-body2.first),2) + pow((body1.second-body2.second),2)) + 0.01);
}
void simulate(vector<BodyClass>& bodies)
{
    float G = 0.00000005;
    for (int i=0; i<bodies.size(); i++)
    {
        for (int j=0; j<bodies.size(); j++)
        {
            if (i!=j)
            {
               float dist = distance_soft(bodies[i].GetPos(), bodies[j].GetPos());
                // dv = a*t = F*t/m
                bodies[i].AddVel( (G * bodies[i].mass / pow(dist, 2)*(bodies[j].pos_x - bodies[i].pos_x))   ,   (G * bodies[i].mass / pow(dist, 2)*(bodies[j].pos_y - bodies[i].pos_y)));
            }
        }
    }
    return;
}
