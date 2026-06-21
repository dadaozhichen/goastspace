#pragma once
#include "SDL3/SDL_render.h"
#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <memory>
#include <string>
#include<unordered_map>
#include "game.h"

struct TTF_FontDeleter {
    void operator()(TTF_Font* font) const {
        if(font) TTF_CloseFont(font);
    }
};
struct SDL_TextureDeleter {
    void operator()(SDL_Texture* texture) const {
        if (texture) SDL_DestroyTexture(texture);
    }
};
struct MIX_AudioDeleter {
    void operator()(MIX_Audio* audio) const {
        if (audio) MIX_DestroyAudio(audio);
    }
};
class AssetStore
{
    std::unordered_map<std::string, std::unique_ptr<SDL_Texture,SDL_TextureDeleter>> texture_;
    std::unordered_map<std::string, std::unique_ptr<MIX_Audio,MIX_AudioDeleter>> sounds_;
    std::unordered_map<std::string, std::unique_ptr<MIX_Audio,MIX_AudioDeleter>> music_;
    std::unordered_map<std::string, std::unique_ptr<TTF_Font,TTF_FontDeleter>> fonts_;

protected:
    Game& game = Game::GetInstance();
public:

    AssetStore(){}
    ~AssetStore() = default;

    void loadImage(const std::string& file_path);
    void loadSound(const std::string& file_path);
    void loadMusic(const std::string& file_path);
    void loadFont(const std::string& file_path,float font_size);

    SDL_Texture* getImage(const std::string& file_path);
    MIX_Audio* getSound(const std::string& file_path);
    MIX_Audio* getMusic(const std::string& file_path);
    TTF_Font* getFont(const std::string& file_path);

};