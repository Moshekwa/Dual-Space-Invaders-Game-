#include "EntityImageLoader.h"
#include <string>
using std::string;

EntityImageLoader::EntityImageLoader()
{
    auto numberOfTextures = 4;
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
    vector<string> image_filenames{ "player1.png", "player2.png", "laser1.png", "laser1.png" };
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
