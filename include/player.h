#pragma once 
#include"actor.h"
#include"scene.h"

class Player:public Actor
{
public:
    Player()=default;
    virtual ~Player()=default;
    virtual void init() override;
    virtual void handleEvents(SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

    void KeyboardControl();
    void move(float dt);

};