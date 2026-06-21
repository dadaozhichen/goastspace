#include "asset_store.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_render.h"
#include "SDL3_image/SDL_image.h"
#include "SDL3_mixer/SDL_mixer.h"
#include "SDL3_ttf/SDL_ttf.h"
#include <memory>

void AssetStore::loadImage(const std::string& file_path){
    SDL_Texture* texture = IMG_LoadTexture(game.getRender(), file_path.c_str());
    if(texture == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Fail to load image %s", file_path.c_str());
        return ;
    }
    std::unique_ptr<SDL_Texture,SDL_TextureDeleter> ptr(texture);
    texture_.emplace(file_path,std::move(ptr));
}  

void AssetStore::loadSound(const std::string& file_path){
    MIX_Audio* sound = MIX_LoadAudio(NULL,file_path.c_str(),true);
    if(sound == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Fail to load sound %s", file_path.c_str());
        return ;
    }
    std::unique_ptr<MIX_Audio,MIX_AudioDeleter> ptr(sound);
    sounds_.emplace(file_path,std::move(ptr));
}

void AssetStore::loadMusic(const std::string& file_path){
    MIX_Audio* music = MIX_LoadAudio(NULL,file_path.c_str(),false);
    if(music == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Fail to load music %s", file_path.c_str());
        return ;
    }
    std::unique_ptr<MIX_Audio,MIX_AudioDeleter> ptr(music);
    music_.emplace(file_path,std::move(ptr));
}

void AssetStore::loadFont(const std::string& file_path,float font_size){
    TTF_Font* font = TTF_OpenFont(file_path.c_str(), font_size);
    if(font == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Fail to load font %s", file_path.c_str());
        return ;
    }
    std::unique_ptr<TTF_Font,TTF_FontDeleter> ptr(font);
    fonts_.emplace(file_path,std::move(ptr));
}

SDL_Texture* AssetStore::getImage(const std::string& file_path){
    auto iter = texture_.find(file_path);
    if(iter == texture_.end())
    {
        loadImage(file_path);
        iter = texture_.find(file_path);
    }
    if(iter == texture_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Fail to get image %s", file_path.c_str());
        return nullptr;
    }
    return iter->second.get();
}

MIX_Audio* AssetStore::getSound(const std::string& file_path)
{
    auto iter = sounds_.find(file_path);
    if(iter == sounds_.end())
    {
        loadImage(file_path);
        iter = sounds_.find(file_path);
    }
    if(iter == sounds_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Fail to get sound %s", file_path.c_str());
        return nullptr;
    }
    return iter->second.get();
}

MIX_Audio* AssetStore::getMusic(const std::string& file_path){
    auto iter = music_.find(file_path);
    if(iter == music_.end())
    {
        loadImage(file_path);
        iter = music_.find(file_path);
    }
    if(iter == music_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Fail to get music %s", file_path.c_str());
        return nullptr;
    }
    return iter->second.get();
}

TTF_Font* AssetStore::getFont(const std::string& file_path){
    auto iter = fonts_.find(file_path);
    if(iter == fonts_.end())
    {
        loadImage(file_path);
        iter = fonts_.find(file_path);
    }
    if(iter == fonts_.end())
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Fail to get font %s", file_path.c_str());
        return nullptr;
    }
    return iter->second.get();
}