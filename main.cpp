#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Network.hpp>
//#include <SFML/Window.hpp>

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
	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("mario.ogg"))
		return EXIT_FAILURE;
	// Play the music
	music.play();
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
		
		double speed = 0.1;

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

		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(sprite);
		// Draw the string
		//window.draw(text);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}