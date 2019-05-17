
#include "lines.h"

MyLines::MyLines(sf::RenderWindow *wind_, unsigned int max_shapes_, sf::Vector2i size_) {
	max_shapes = max_shapes_;

	window = wind_;

	size = size_;

	dirSpeedX = new float[max_shapes];
	dirSpeedY = new float[max_shapes];

	int tempX, tempY;
	tempX = size_.x / 15;
	tempY = size_.y / 10;

	srand(time(0));
	bool dir; // true - right, false - left 

	int x = 10, y = 10;
	for (int i = 0; i < max_shapes; i++, x+=tempX) {
		if (x >= size_.x) {
			y += tempY;
			x = 0;
		}
			
		// Create shapes
		// and set params
		sf::CircleShape TempShape(2);
		TempShape.setFillColor(sf::Color::Yellow);
		TempShape.setPosition(x, y);
		shapes.push_back(TempShape);


		// Create directions
		dirSpeedY[i] = (1 + rand() % 5) * 0.01; //Speed y
		dirSpeedX[i] = (1 + rand() % 5) * 0.01; //Speed y

		dir = rand() % 2;

		dir != true ? dirSpeedX[i] : dirSpeedX[i] -= dirSpeedX[i] * 2;
	}

}

int sqrt(int &arg) {
	return (arg * arg);
}

void MyLines::cylleUpdate() {

	sf::Clock clock;
	float time;
	while (window->isOpen()) {
		time = clock.getElapsedTime().asMilliseconds();
		clock.restart();


		sf::Event event;
		while (window->pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		update(time);
		window->display();

	}


}

void MyLines::update(float &time) {

	sf::Vertex lines[2];

	sf::Color color(136, 207, 43);

	float timer = 0;

	int countDirs = 0;

		// Check position
		// Lines
		for (auto it = shapes.begin(); it != shapes.end(); it++) {
			it->setPosition(
				it->getPosition().x + dirSpeedX[countDirs] * time,
				it->getPosition().y + dirSpeedY[countDirs] * time
			);

			if (it->getPosition().x > size.x) {
				it->setPosition(0, it->getPosition().y);
			}
			if (it->getPosition().y > size.y) {
				it->setPosition(it->getPosition().x, 0);
			}
			if (it->getPosition().x < -1) {
				it->setPosition(size.x-1, it->getPosition().y);
			}
			/////////
			for (auto shape = shapes.begin(); shape != shapes.end(); shape++) {

				int x = shape->getPosition().x - it->getPosition().x;
				int y = shape->getPosition().y - it->getPosition().y;

				int distance = sqrt(x * x + y * y);
				if (distance < 100) {
					lines[0] = sf::Vertex(sf::Vector2f(it->getPosition().x+2, it->getPosition().y+2));
					lines[1] = sf::Vertex(sf::Vector2f(shape->getPosition().x+2, shape->getPosition().y+2));

					color.a = 255 - ((distance + 155) % 255);
					
					lines[0].color = color;
					lines[1].color = color;

					window->draw(lines, 2, sf::Lines);
				} 

			}

			countDirs++;
		}
		countDirs = 0;
		///////////////////////////////


		for (auto t : shapes) {
			window->draw(t);
		}
		

}
