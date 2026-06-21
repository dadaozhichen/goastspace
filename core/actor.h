#pragma once 
#include "object_world.h"

class Actor:public ObjectWorld
{
protected:
    glm::vec2 velocity_ = glm::vec2(0,0);
    float max_speed_ = 10.0;
public:
    Actor()=default;
    ~Actor()=default;
    glm::vec2 GetVelocity() const {return velocity_;}
    void SetVelocity(const glm::vec2 &v){velocity_=v;}
    float GetMaxSpeed() const {return max_speed_;}
    void SetMaxSpeed(const float& max_speed) {max_speed_ = max_speed;}
};