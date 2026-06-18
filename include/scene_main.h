#pragma once 

#include "scene.h"
#include<memory>
#include"player.h"
class Player;

class SceneMain:public Scene{
    std::unique_ptr<Player> player_;
public:
    SceneMain() = default;
    virtual ~SceneMain() = default;
    virtual void init() override;
    virtual void handleEvents(SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override; 
private:
    void renderBackground();
};
 