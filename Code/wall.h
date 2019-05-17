#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>

class Wall {
public:
    Wall(sf::Texture &texture, sf::Vector2f pos, sf::Vector2f scaleSprite, bool isWall = true);

    sf::Sprite& getSprite();
private:
    sf::Texture *texture;
    sf::Sprite sprite;
    bool isWall;

    sf::Vector2f position;
};

#endif 
