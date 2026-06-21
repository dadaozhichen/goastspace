#pragma once 

#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<SDL3_mixer/SDL_mixer.h>
#include<glm/glm.hpp>
#include<string> 
#include<memory>
#include "SDL3/SDL_properties.h"

class Scene;
class AssetStore;

struct SDL_WindowDeleter{
    void operator()(SDL_Window* window)const 
    {
        if(window) SDL_DestroyWindow(window);
    }
};

struct SDL_RendererDeleter{
    void operator()(SDL_Renderer* renderer)const 
    {
        if(renderer) SDL_DestroyRenderer(renderer);
    }
};
struct MIX_MixerDeleter {
    void operator()(MIX_Mixer* mixer) const {
        if (mixer) MIX_DestroyMixer(mixer);
    }
};
struct MIX_TrackDeleter{
    void operator()(MIX_Track* track) const {
        if(track) MIX_DestroyTrack(track);
    }
};

class Game
{
    std::unique_ptr<AssetStore> asset_store_;
    glm::vec2 screen_size_ = glm::vec2(0);
    bool is_running = true;
    std::unique_ptr<Scene> current_scene;
    
    Uint64 FPS_ = 60;
    Uint64 frameDelay = 0;
    float dt_ = 0.0f;

    std::unique_ptr<SDL_Window,SDL_WindowDeleter> window;
    std::unique_ptr<SDL_Renderer,SDL_RendererDeleter> renderer;
    std::unique_ptr<MIX_Mixer,MIX_MixerDeleter> mixer;
    std::unique_ptr<MIX_Track,MIX_TrackDeleter> music_track;  


    SDL_PropertiesID loop_props;
    

    Game();
    ~Game();
    Game(const Game&) =delete ;
    Game& operator=(const Game&) = delete;

public:    
    SDL_Renderer* getRender()
    {
        return renderer.get();
    }
    MIX_Mixer* getMixer()
    {
        return mixer.get();
    }
    MIX_Track* getMusic()
    {
        return music_track.get();
    }
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
    void setScene(std::unique_ptr<Scene> scene);


    glm::vec2 getScreenSize() const { return screen_size_; } 
    Scene* getCurrentScene() const {return current_scene.get(); }

    void drawGrid(const glm::vec2& top_left,const glm::vec2& bottom_right,float grid_width,SDL_FColor fcolor);
    void drawBoundary(const glm::vec2& top_left,const glm::vec2& bottom_right,float boundary_width,SDL_FColor fcolor);
};

