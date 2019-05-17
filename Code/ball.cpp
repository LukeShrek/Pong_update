#include "ball.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

Ball::Ball(Texture &texture, Vector2f pos)
{
    ballPosition = pos;
    ballTexture = new Texture(texture);
    ballSprite.setTexture(*ballTexture);
    ballSprite.setOrigin(ballTexture->getSize().x / 2, ballTexture->getSize().y / 2);
    ballSprite.setScale(0.5, 0.5);
    ballSprite.setPosition(ballPosition);
    HSpeed = 0.4;
    VSpeed = 0.4;

    VDir = VDirection::VNONE;
    HDir = HDirection::HNONE;
}

Ball::~Ball()
{
    delete ballTexture;
}


	
void Ball::update(float &time, Player &pl1, Player &pl2, Wall &wallUp, Wall &wallDown, Wall &left, Wall &right, unsigned short &one, unsigned short &two)
{
	SoundBuffer ballSoundBuffer;
	ballSoundBuffer.loadFromFile("source/Music/ball.wav");
	Sound ballSound(ballSoundBuffer);

    if (VDir == VNONE && HDir == HNONE)
	{
        randomDir();
    }

    ////// PLAYER //////
    if (ballSprite.getGlobalBounds().intersects(pl1.getSprite().getGlobalBounds())){
        HDir = RIGHT;
		ballSound.play();
        if (VDir == UP)
		{
            VDir = UP;
        }
		else
		{
            VDir = DOWN;
        }

    }
    if (ballSprite.getGlobalBounds().intersects(pl2.getSprite().getGlobalBounds())){
        HDir = LEFT;
		ballSound.play();
        if (VDir == UP)
		{
            VDir = UP;
        } 
		else 
		{
            VDir = DOWN;
        }
    }
    ////// PLAYER //////
    ////// WALL //////

    if (VDir == UP)
	{
        if (ballSprite.getGlobalBounds().intersects(wallUp.getSprite().getGlobalBounds()))
		{
			ballSound.play();
            VDir = DOWN;
        }
    } 
	else if (VDir == DOWN)
	{
        if (ballSprite.getGlobalBounds().intersects(wallDown.getSprite().getGlobalBounds()))
		{
			ballSound.play();
            VDir = UP;
        }
    }

    if (ballSprite.getGlobalBounds().intersects(left.getSprite().getGlobalBounds()))
	{
        ballPosition = sf::Vector2f(780 / 2, 480 / 2);
        HDir = HNONE;
        VDir = VNONE;
        two++;
    }
    if (ballSprite.getGlobalBounds().intersects(right.getSprite().getGlobalBounds()))
	{
        ballPosition = sf::Vector2f(780 / 2, 480 / 2);
        HDir = HNONE;
        VDir = VNONE;
        one++;
    }
    ////// WALL //////
    if (HDir == HDirection::LEFT)
	{
        ballPosition.x -= HSpeed*time;
    } 
	else if (HDir == HDirection::RIGHT)
	{
        ballPosition.x += HSpeed*time;
    }

    if (VDir == VDirection::UP)
	{
        ballPosition.y -= VSpeed*time;
    } 
	else if (VDir == VDirection::DOWN)
	{
        ballPosition.y += VSpeed*time;
    }
    ballSprite.setPosition(ballPosition);
}

Sprite& Ball::getSprite()
{
    return ballSprite;
}

void Ball::randomDir()
{
    bool temp = rand()%2;
    if(temp)
	{
        VDir = UP;
    }
	else 
	{
        VDir = DOWN;
    }
    temp = rand()%2;
    if (temp)
	{
        HDir = RIGHT;
    } 
	else 
	{
        HDir = LEFT;
    }
}

void Ball::reset(Vector2f pos)
{
    ballPosition = pos;
    ballSprite.setPosition(ballPosition);
    HDir = HNONE;
    VDir = VNONE;
}













