#include "gamemenu.h"

GameMenu::GameMenu(sf::Vector2i windowSize, sf::RenderWindow &window)
{
    this->windowSize = windowSize;
    bgTexture.loadFromFile("source/background.png");
    bgSprite.setTexture(bgTexture);
    drawHelp = false;

    fontMenu.loadFromFile("source/font/stan0753.ttf");

	btText1Player = new sf::Text("1 Player", fontMenu, 25);
	btText1Player->setPosition(360, 250);

    btText2Players = new sf::Text("2 Players", fontMenu, 25);
    btText2Players->setPosition(360, 300);

    btTextHelp = new sf::Text("Help", fontMenu, 25);
    btTextHelp->setPosition(360, 350);

    btTextExit = new sf::Text("Exit", fontMenu, 25);
    btTextExit->setPosition(360, 400);

    btTextBack = new sf::Text("Back", fontMenu, 20);
    btTextBack->setPosition(windowSize.x - (50+40), windowSize.y - 50);

    helpText1 = new sf::Text("Player 1: W - UP, S - DOWN\n"
                            "Player 2: Arrow UP - UP, Arrow DOWN - DOWN\n", fontMenu, 20);
    helpText1->setPosition(20, 20);

	helpText2 = new sf::Text("Game project made by Le Minh Binh,\n"
		
							"Music: Titerman - Ed Bogas", fontMenu, 15);
	helpText2->setPosition(20, 400);

}

GameMenu::~GameMenu()
{
	delete btText1Player;
    delete btText2Players;
    delete btTextExit;
    delete btTextHelp;
    delete btTextBack;
    delete helpText1;
	delete helpText2;
}

void GameMenu::update(sf::RenderWindow &window, bool &computer)
{
    sf::Vector2i mousePixel;
    float time;
    sf::Clock clock;
    while(window.isOpen())
	{
        time = clock.getElapsedTime().asMicroseconds();
        time /= 800;
        clock.restart();

        mousePixel = sf::Mouse::getPosition(window);

        sf::Event event;
        while (window.pollEvent(event))
		{
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!drawHelp)
		{
			// 1 PLAYER
			if (btText1Player->getGlobalBounds().contains(mousePixel.x, mousePixel.y))
			{
				btText1Player->setColor(sf::Color::Blue);
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.key.code == sf::Mouse::Left)
						computer = 1;
						break;
				}
			}
			else
			{
				btText1Player->setColor(sf::Color::White);
			}
            // 2 PLAYERS
            if (btText2Players->getGlobalBounds().contains(mousePixel.x, mousePixel.y))
			{
				btText2Players->setColor(sf::Color::Green);
                if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.key.code == sf::Mouse::Left)
						computer = 0;
                        break;
                }
            }
			else
			{
				btText2Players->setColor(sf::Color::White);
            }

            // HELP
            if (btTextHelp->getGlobalBounds().contains(mousePixel.x, mousePixel.y))
			{
                btTextHelp->setColor(sf::Color::Yellow);
                if (event.type == sf::Event::MouseButtonPressed)
				{
                    if (event.key.code == sf::Mouse::Left)
					{
                        drawHelp = true;
                    }
                }

            } 
			else 
			{
                btTextHelp->setColor(sf::Color::White);
            }

            // EXIT
            if (btTextExit->getGlobalBounds().contains(mousePixel.x, mousePixel.y))
			{
                btTextExit->setColor(sf::Color::Red);
                if (event.type == sf::Event::MouseButtonPressed)
				{
                    if (event.key.code == sf::Mouse::Left)
					{
                        window.close();
                    }
                }
            } 
			else 
			{
                btTextExit->setColor(sf::Color::White);
            }
        } 
		else 
		{
            // BACK
            if (btTextBack->getGlobalBounds().contains(mousePixel.x, mousePixel.y))
			{
                btTextBack->setColor(sf::Color::Magenta);
                if (event.type == sf::Event::MouseButtonPressed)
				{
                    if (event.key.code == sf::Mouse::Left)
					{
                        drawHelp = false;
                    }
                }
            } 
			
			else 
			{
                btTextBack->setColor(sf::Color::White);
            }
        }

        window.clear();
        drawMenu(window);
        window.display();
    }
}

void GameMenu::drawMenu(sf::RenderWindow &window) const
{
    window.draw(bgSprite);
    if (!drawHelp)
	{
		window.draw(*btText1Player);
        window.draw(*btText2Players);
        window.draw(*btTextExit);
        window.draw(*btTextHelp);
    } 
	else
	{
        window.draw(*btTextBack);
        window.draw(*helpText1);
		window.draw(*helpText2);
    }
}



