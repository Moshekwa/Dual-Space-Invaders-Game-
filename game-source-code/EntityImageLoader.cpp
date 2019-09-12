#include "EntityImageLoader.h"
#include <string>
using std::string;

EntityImageLoader::EntityImageLoader()
{
    auto numberOfTextures = 25;
    for(int i = 0; i < numberOfTextures; i++) {
        auto _texture = Texture{};
        _textures.push_back(_texture);
        shared_ptr<Sprite> _sprite{ new Sprite };
        _sprites.push_back(_sprite);
    }
}

void EntityImageLoader::loadEntityImages()
{
    loadImages();
    setSprites();
}

Sprites EntityImageLoader::getSprites()
{
    return _sprites;
}

void EntityImageLoader::loadImages()
{
    vector<string> image_filenames{ "player1.png", "player2.png", "laser1.png", "laser1.png", "green_alien.png",
        "purple_alien.png", "red_alien.png", "up_green_alien.png", "up_purple_alien.png", "up_red_alien.png",
        "splash_screen.png", "gamewon.png", "gamelost.png", "green_alien2.png", "green_alien3.png", "purple_alien2.png",
        "purple_alien3.png", "red_alien2.png", "red_alien3.png", "up_green_alien2.png", "up_green_alien3.png",
        "up_purple_alien2.png", "up_purple_alien3.png", "up_red_alien2.png", "up_red_alien3.png" };
    for(auto i = 0u; i < _textures.size(); i++) {
        if(!_textures.at(i).loadFromFile(image_filenames.at(i).c_str()))
            exit(1);
    }
}

void EntityImageLoader::setSprites()
{
    for(auto i = 0u; i < _textures.size(); i++) {
        _textures.at(i).setSmooth(true);
        _sprites.at(i)->setTexture(_textures.at(i), true);
    }
}
