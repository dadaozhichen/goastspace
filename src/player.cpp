#include "player.h"
#include<memory>

void Player::init() {
    max_speed_=250.0f;
}
void Player::handleEvents(SDL_Event& event){

}
void Player::update(float dt) {
    KeyboardControl();
    move(dt);
    velocity_*=0.9;
}
void Player::move(float dt){
    setPosition(position_+velocity_*dt);
    position_ = glm::clamp(position_,glm::vec2(0),game.getCurrentScene()->getWorldSize()+glm::vec2(-30));
}
void Player::render(){
    //SDL_Log("render begin!");
    game.drawBoundary(render_position_,render_position_+glm::vec2(20,20),5.0f,{1.0,0.0,0.0,1.0});
}
void Player::clean(){

} 

void Player::KeyboardControl(){
    auto currentKeyStates = SDL_GetKeyboardState(nullptr);
    if(currentKeyStates[SDL_SCANCODE_W]){
        velocity_.y=-max_speed_;
        //SDL_Log("W");
    }
    if(currentKeyStates[SDL_SCANCODE_S])
    {
        velocity_.y=max_speed_;
        //SDL_Log("S");
    }
    if(currentKeyStates[SDL_SCANCODE_A])
    {
        velocity_.x=-max_speed_;
        //SDL_Log("A");
    }
    if(currentKeyStates[SDL_SCANCODE_D])
    {
        velocity_.x=max_speed_;
        //SDL_Log("D");
    }
    
    auto final_v = sqrt(velocity_.x*velocity_.x+velocity_.y*velocity_.y);
    if(final_v>max_speed_)
    {
        velocity_.x *=max_speed_/final_v;
        velocity_.y *=max_speed_/final_v; 
    }
}