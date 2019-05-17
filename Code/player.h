#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	Player(sf::Texture &texture, sf::Vector2f pos, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);

	void update(float time);
	void reset(sf::Vector2f pos);
	sf::Vector2f playerPosition;

	sf::Sprite& getSprite();

	enum Direction
	{
		NONE,
		UP,
		DOWN
	};

	Direction getDir();

protected:
	float speed;
	Direction dirPlr;

	sf::Texture *texture;
	sf::Sprite playerSprite;

	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;

	virtual void Player::Moving(float time);
	
};

class BOT : public Player
{
public:
	BOT(sf::Texture &texture, sf::Vector2f pos, sf::Vector2f* ballPosition);
	sf::Clock BOTTimer;
	sf::Time BOTTime = sf::seconds(0.1f);
	float ballRadius = 25;
	float paddleSize = 100;

protected:
	void Moving(float time) override;
	sf::Vector2f* ballPosition;
};
	
#endif 