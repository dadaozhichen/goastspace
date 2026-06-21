#include<SDL3/SDL.h>
#include<glm/common.hpp>
#include <memory>
#include<string>
#include "game.h"
#include "scene_main.h"

int main(int,char**)
{
    auto& game = Game::GetInstance();
    if(!game.init("Goastspace",800,600)){
        return 1;
    }
    game.setScene(std::make_unique<SceneMain>());
    game.run();
    return 0;
}
