#ifndef ENTITYIMAGELOADER_H_INCLUDED
#define ENTITYIMAGELOADER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

using std::shared_ptr;
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

private:
    Sprites _sprites;
    Textures _textures;
    void loadImages();
    void setSprites();
};

#endif // ENTITYIMAGELOADER_H_INCLUDED