#include "game.h"
#include "object.h"
#include "scene_main.h" 

void Game::run()
{
    while(is_running){
        auto start = SDL_GetTicksNS();
        handleEvents();
        update(dt_);
        render();
        auto end = SDL_GetTicksNS();
        auto elapsed = end-start;
        if(elapsed<frameDelay){
            SDL_DelayNS(frameDelay-elapsed);
        }
        else{
            dt_ = elapsed/1e9;
        }

        // SDL_Log("FPS:%lf",1.0/dt_);
    }
}

bool Game::init(std::string title, int width, int heigth)
{
    screen_size_ = glm::vec2(width,heigth);
    if(!SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO)){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL初始化失败:%s\n",SDL_GetError());
        return false;
    }
    if(!TTF_Init()){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"SDL_ttf初始化失败:%s\n",SDL_GetError());
        return false;
    }
    SDL_Window* raw_window = nullptr;
    SDL_Renderer* raw_renderer = nullptr;
    if(!SDL_CreateWindowAndRenderer(title.c_str(),width,heigth,SDL_WINDOW_RESIZABLE,&raw_window,&raw_renderer)){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"窗口或渲染器初始化失败:%s\n",SDL_GetError());
        return false;
    }
    window.reset(raw_window);
    renderer.reset(raw_renderer);

    SDL_SetRenderLogicalPresentation(renderer.get(),width,heigth,SDL_LOGICAL_PRESENTATION_LETTERBOX);

    frameDelay = 1e9/FPS_;

    current_scene = std::make_shared<SceneMain>();
    current_scene->init();
    return true;
}

void Game::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_EVENT_QUIT:
                is_running=false;
                break;
            default:
                current_scene->handleEvents(event);

        }
    }
}

void Game::update(float dt)
{
    current_scene->update(dt);
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer.get(),0,0,0,255);
    SDL_RenderClear(renderer.get());
    current_scene->render();
    SDL_RenderPresent(renderer.get());
}

void Game::clean()
{
    if(current_scene){
        current_scene->clean();
        //delete current_scene;
    }
    if(renderer){
        //SDL_DestroyRenderer(renderer);
    }
    if(window) {
        //SDL_DestroyWindow(window);
    }
    TTF_Quit();
    SDL_Quit();
}

void Game::drawGrid(const glm::vec2 &top_left, const glm::vec2 &bottom_right, float grid_width, SDL_FColor fcolor)
{
    
    SDL_SetRenderDrawColorFloat(renderer.get(),fcolor.r,fcolor.g,fcolor.b,fcolor.a);
    for (float x=top_left.x;x<=bottom_right.x;x+=grid_width)
    {
        SDL_RenderLine(renderer.get(),x,top_left.y,x,bottom_right.y);
    }
    for (float y=top_left.y;y<=bottom_right.y;y+=grid_width)
    {
        SDL_RenderLine(renderer.get(),top_left.x,y,bottom_right.x,y);
    }
    SDL_SetRenderDrawColorFloat(renderer.get(),0,0,0,1);
}

void Game::drawBoundary(const glm::vec2 &top_left, const glm::vec2 &bottom_right, float boundary_width, SDL_FColor fcolor)
{
    SDL_SetRenderDrawColorFloat(renderer.get(),fcolor.r,fcolor.g,fcolor.b,fcolor.a);
    for(float i=0;i<boundary_width;i++)
    {
        SDL_FRect rect = {
            top_left.x-i,
            top_left.y-i,
            bottom_right.x-top_left.x+2*i,
            bottom_right.y-top_left.y+2*i
        };
        SDL_RenderRect(renderer.get(),&rect);
    }
    SDL_SetRenderDrawColorFloat(renderer.get(),0,0,0,1);
}
