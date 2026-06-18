#pragma once 

#include "game.h"

class Object {
protected:
    Game& game = Game::GetInstance();
public:
    Object() = default;
    virtual ~Object() = default;

    virtual void init(){}
    virtual void handleEvents(SDL_Event& event){}
    virtual void update(float dt) {}
    virtual void render() {}
    virtual void clean() {}
};
