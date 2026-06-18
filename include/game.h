#pragma once 


#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<SDL3_mixer/SDL_mixer.h>
#include<glm/glm.hpp>
#include<string> 
#include<memory>

class Scene;

struct SDLWindowDeleter{
    void operator()(SDL_Window* window)const 
    {
        if(window) SDL_DestroyWindow(window);
    }
};

struct SDLRendererDeleter{
    void operator()(SDL_Renderer* renderer)const 
    {
        if(renderer) SDL_DestroyRenderer(renderer);
    }
};

class Game 
{
    glm::vec2 screen_size_ = glm::vec2(0);
    bool is_running = true;
    std::shared_ptr<Scene> current_scene;
    
    Uint64 FPS_ = 60;
    Uint64 frameDelay = 0;
    float dt_ = 0.0f;

    std::unique_ptr<SDL_Window,SDLWindowDeleter> window;
    std::unique_ptr<SDL_Renderer,SDLRendererDeleter> renderer;
    

    Game()=default;
    Game(const Game&) =delete ;
    Game& operator=(const Game&) = delete;

public:
    static Game& GetInstance()
    {
        static Game instance;
        return instance;
    }
    void run();
    bool init(std::string title,int width,int heigth);
    void handleEvents();
    void update(float dt);
    void render();
    void clean();


    glm::vec2 getScreenSize() const { return screen_size_; } 
    std::shared_ptr<Scene> getCurrentScene() const {return current_scene; }

    void drawGrid(const glm::vec2& top_left,const glm::vec2& bottom_right,float grid_width,SDL_FColor fcolor);
    void drawBoundary(const glm::vec2& top_left,const glm::vec2& bottom_right,float boundary_width,SDL_FColor fcolor);
};

