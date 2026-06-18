#pragma once 

#include "object.h"
#include <glm/glm.hpp>
#include <vector>

class Scene:public Object
{
protected:
    glm::vec2 world_size_ = glm::vec2();
    glm::vec2 camera_position_ = glm::vec2(0);
    std::vector<Object*> objects_; 


public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void init() override {}
    virtual void handleEvents(SDL_Event& event) override {}
    virtual void update(float dt) override {}
    virtual void render() override {}
    virtual void clean() override {} 

    void SetCameraPosition(const glm::vec2 camera_position){camera_position_=camera_position;}
    glm::vec2 getWorldSize(){return world_size_;}
    void setWorldSize(const glm::vec2 world_size){world_size_=world_size;}
    glm::vec2 WorldToScreen(const glm::vec2 &position) const {return position-camera_position_;}
    glm::vec2 ScreenToWorld(const glm::vec2 &position) const {return position+camera_position_;}
};
