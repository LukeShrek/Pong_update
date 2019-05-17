#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "player.h"
#include "wall.h"

using namespace sf;

class Ball{
public:
    Ball(Texture &texture, Vector2f pos);
    ~Ball();
	Vector2f ballPosition;

    Sprite& getSprite();
    void update(float &time, Player &pl1, Player &pl2, Wall &wallUp, Wall &wallDown, Wall &left, Wall &right, unsigned short &one, unsigned short &two);

    void reset(Vector2f pos);

    enum VDirection{
        UP,
        DOWN,
        VNONE
    };

    enum HDirection{
        RIGHT,
        LEFT,
        HNONE
    };

private:
    // Texture
    Texture *ballTexture;
    Sprite ballSprite;

    // fiz parameters
    float HSpeed, VSpeed;
    VDirection VDir;
    HDirection HDir;
	//Vector2f position;

    //Ball func
    void randomDir();
};

#endif 
