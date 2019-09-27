/**
 * @file ImageLoader.h
 * @class ImageLoader
 * @brief Responsible for loading all the images and texts that will be displayed on the game window.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef ENTITYIMAGELOADER_H_INCLUDED
#define ENTITYIMAGELOADER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;
using std::vector;
using namespace sf;

typedef vector<shared_ptr<Sprite>> Sprites;
typedef vector<shared_ptr<Text>> Texts;
typedef vector<Texture> Textures;

class ImageLoader
{
public:
    ImageLoader();
    void loadImagesAndSetSprites();
    Sprites getSprites() const;
    Texts getTexts() const;
    ~ImageLoader(){};

private:
    Sprites _sprites;
    Textures _textures;
    Texts _texts;
    Font _font;
    void loadImages();
    void setSprites();
    void createTexts();
};

#endif // ENTITYIMAGELOADER_H_INCLUDED