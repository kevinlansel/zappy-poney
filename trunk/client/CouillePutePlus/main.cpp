//
// main.cpp for client in /home/haz3/projet/zappy-poney/client/CouillePutePlus
// 
// Made by Maxime Wojciak
// Login   <wojcia_m@epitech.net>
// 
// Started on  Thu Jun 27 17:45:52 2013 Maxime Wojciak
// Last update Thu Jun 27 19:24:06 2013 Maxime Wojciak
//

#include	<SFML/Audio.hpp>
#include	<SFML/Graphics.hpp>
#include	"Windows.hpp"

using namespace sf;

int		main(int ac, char *av[])
{
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  // Load a sprite to display
  sf::Texture texture;
  if (!texture.loadFromFile("../ressources/pictures/noctali.png"))
    return EXIT_FAILURE;
  sf::Sprite sprite(texture);
  // Create a graphical text to display
  sf::Font font;
  if (!font.loadFromFile("../ressources/fonts/Sansation_Bold.ttf"))
    return EXIT_FAILURE;
  sf::Text text("Hello SFML", font, 50);
  // Load a music to play
  sf::Music music;
  if (!music.openFromFile("../ressources/audio/contact.wav"))
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
