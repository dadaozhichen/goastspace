#include<SDL3/SDL.h>
#include<glm/common.hpp>
#include<string>
#include "game.h"

int main(int,char**)
{
    auto& game = Game::GetInstance();
    if(!game.init("Goastspace",800,600)){
        return 1;
    }
    game.run();
    game.clean();
    return 0;
}
