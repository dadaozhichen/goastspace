#include"scene_main.h"
#include"player.h"

void SceneMain::init()
{
    world_size_ = game.getScreenSize()*3.0f;
    camera_position_ = world_size_/2.0f-game.getScreenSize()/2.0f;
    player_ = std::make_unique<Player>();
    player_->init();
    player_->setPosition(world_size_/2.0f);
}

void SceneMain::handleEvents(SDL_Event& event) 
{
}

void SceneMain::update(float dt)
{
    //camera_position_ +=glm::vec2(20.0f,20.0f)*dt;
    player_->update(dt);
    SetCameraPosition(player_->getPosition()-game.getScreenSize()/2.0f);
}

void SceneMain::render()
{
    renderBackground();
    player_->render();
}

void SceneMain::clean()
{
    player_->clean();
}

void SceneMain::renderBackground()
{
    glm::vec2 snap_cam = {std::floor(camera_position_.x),std::floor(camera_position_.y)};
    auto start = -snap_cam;
    auto end = world_size_-snap_cam;
    game.drawGrid(start,end,80.0f,{0.5,0.5,0.5,1.0});
    game.drawBoundary(start,end,5.0f,{1.0,1.0,1.0,1.0});
}
