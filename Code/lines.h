#ifndef LINES_H
#define LINES_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iterator>
#include <cstdlib>

class MyLines {
public:
	MyLines(sf::RenderWindow *wind_, unsigned int max_shapes_, sf::Vector2i size_);

	void update(float &time);
	void cylleUpdate();
protected:
	sf::RenderWindow *window;
	unsigned int max_shapes;

	sf::Vector2i leftTop, size;
	
	std::vector<sf::CircleShape> shapes;
	float *dirSpeedX;
	float *dirSpeedY;
};


#endif