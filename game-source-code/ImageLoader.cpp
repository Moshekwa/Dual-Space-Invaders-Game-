#include "ImageLoader.h"
#include <string>
using std::string;

ImageLoader::ImageLoader()
{
    auto numberOfTextures = 33;
    for(int i = 0; i < numberOfTextures; i++) {
	auto _texture = Texture{};
	_textures.push_back(_texture);
	shared_ptr<Sprite> _sprite{ new Sprite };
	_sprites.push_back(_sprite);
    }
    if(!_font.loadFromFile("font.ttf")) {
	exit(1);
    }
}

void ImageLoader::loadImagesAndSetSprites()
{
    loadImages();
    setSprites();
    createTexts();
}

Sprites ImageLoader::getSprites() const
{
    return _sprites;
}

void ImageLoader::loadImages()
{
    vector<string> image_filenames{ "player1.png", "player2.png", "laser1.png", "laser1.png", "green_alien.png",
	"purple_alien.png", "red_alien.png", "up_green_alien.png", "up_purple_alien.png", "up_red_alien.png",
	"splash_screen.png", "gamewon.png", "gamelost.png", "green_alien2.png", "green_alien3.png", "purple_alien2.png",
	"purple_alien3.png", "red_alien2.png", "red_alien3.png", "up_green_alien2.png", "up_green_alien3.png",
	"up_purple_alien2.png", "up_purple_alien3.png", "up_red_alien2.png", "up_red_alien3.png", "laser2.png",
	"shield1.png", "upShield1.png", "shield2.png", "upShield2.png", "shield3.png", "upShield3.png",
	"playerlife.png" };

    for(auto i = 0u; i < _textures.size(); i++) {
	if(!_textures.at(i).loadFromFile(image_filenames.at(i).c_str()))
	    exit(1);
    }
}

void ImageLoader::setSprites()
{
    for(auto i = 0u; i < _textures.size(); i++) {
	_textures.at(i).setSmooth(true);
	_sprites.at(i)->setTexture(_textures.at(i), true);
    }
}

void ImageLoader::createTexts()
{
    auto _text = make_shared<Text>();
    _text->setFont(_font);
    _texts.push_back(_text);

    auto _text2 = make_shared<Text>();
    _text2->setFont(_font);
    _texts.push_back(_text2);
}

Texts ImageLoader::getTexts() const
{
    return _texts;
}
