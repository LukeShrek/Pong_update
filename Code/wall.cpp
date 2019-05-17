#include "wall.h"

Wall::Wall(sf::Texture &texture, sf::Vector2f pos, sf::Vector2f scaleSprite, bool isWall){
    this->texture = &texture;
    position = pos;
    sprite.setTexture(*(this->texture));
    sprite.setPosition(position);
    sprite.setScale(scaleSprite);
    this->isWall = isWall;
}

sf::Sprite& Wall::getSprite(){
    return sprite;
}
