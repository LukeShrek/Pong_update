#include "player.h"

Player::Player()
{
}

Player::Player(sf::Texture &texture, sf::Vector2f pos, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey){
    this->texture = &texture;
    this->playerPosition = pos;
    this->playerSprite.setTexture(texture);
    this->playerSprite.setPosition(playerPosition);
    this->upKey = upKey;
    this->downKey = downKey;
    this->speed = 0.3f;
    dirPlr = Direction::NONE;
}

Player::Direction Player::getDir(){
    return dirPlr;
}

void Player::Moving(float time) {
	if (sf::Keyboard::isKeyPressed(upKey))
	{
		if (playerPosition.y >= 50) {
			dirPlr = UP;
			playerPosition.y -= time * speed;
		}
		else
		{
			playerPosition.y += 50 - playerPosition.y;
		}
	}
	if (sf::Keyboard::isKeyPressed(downKey))
	{
		if (playerPosition.y + playerSprite.getGlobalBounds().height <= 470)
		{
			dirPlr = DOWN;
			playerPosition.y += time * speed;
		}
		else
		{
			playerPosition.y -= playerPosition.y - (470 - playerSprite.getGlobalBounds().height);
		}
	}
	this->playerSprite.setPosition(playerPosition);
}

void Player::update(float time){
    Moving(time);
}

sf::Sprite& Player::getSprite(){
    return this->playerSprite;
}

void Player::reset(sf::Vector2f pos){
	playerPosition = pos;
    playerSprite.setPosition(playerPosition);
}


BOT::BOT(sf::Texture & texture, sf::Vector2f pos, sf::Vector2f* ballPosition)
{
	this->texture = &texture;
	this->playerPosition = pos;
	this->playerSprite.setTexture(texture);
	this->playerSprite.setPosition(playerPosition);
//	this->upKey = upKey;
//	this->downKey = downKey;
	this->speed = 0.3f;
	dirPlr = Direction::NONE;
	this->ballPosition = ballPosition;
}

void BOT::Moving(float time)
{
	if (ballPosition->y + ballRadius < playerPosition.y + paddleSize / 2)
	{
		if (playerPosition.y >= 50) {
			dirPlr = UP;
			playerPosition.y -= time * speed;
		}
		else
		{
			playerPosition.y += 50 - playerPosition.y;
		}

	}else if (ballPosition-> y + ballRadius > playerPosition.y + paddleSize / 2)
	{
		if (playerPosition.y + playerSprite.getGlobalBounds().height <= 470)
		{
			dirPlr = DOWN;
			playerPosition.y += time * speed;
		}
		else
		{
			playerPosition.y -= playerPosition.y - (470 - playerSprite.getGlobalBounds().height);
		}
	}
	this->playerSprite.setPosition(playerPosition);
}