#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

using namespace System;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("mario.png"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Hello SFML", font, 50);
	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("mario.ogg"))
		return EXIT_FAILURE;
	// Play the music
	music.play();
	
	// starts the clock
	sf::Clock clock;

	// last mouse position
	sf::Vector2i last_mouse_position;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time elapsedTime = clock.getElapsedTime();
		clock.restart();
		
		double speed = 0.0001 * elapsedTime.asMicroseconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite.setPosition(sprite.getPosition().x - speed, sprite.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sprite.setPosition(sprite.getPosition().x + speed, sprite.getPosition().y);
		}
		
		// only if its a new mouse position
		if (last_mouse_position != sf::Mouse::getPosition())
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Console::WriteLine("Klick Maustaste: Links; X: " + sf::Mouse::getPosition().x 
					+ "; Y: " + sf::Mouse::getPosition().x);
				last_mouse_position = sf::Mouse::getPosition();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
			{
				Console::WriteLine("Klick Maustaste: Mitte; X: " + sf::Mouse::getPosition().x
					+ "; Y: " + sf::Mouse::getPosition().x);
				last_mouse_position = sf::Mouse::getPosition();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				Console::WriteLine("Klick Maustaste: Rechts; X: " + sf::Mouse::getPosition().x
					+ "; Y: " + sf::Mouse::getPosition().x);
				last_mouse_position = sf::Mouse::getPosition();
			}
		}

		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(sprite);
		// Draw the string
		window.draw(text);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}