#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    std::vector<Missile*> listeMissiles;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Space Survivor");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("ressources/cute_image.jpg"))
        return EXIT_FAILURE;

    sf::Sprite sprite(texture);

    sf::Texture asteroidt;
    if(!asteroidt.loadFromFile("ressources/asteroid.png"))
      return EXIT_FAILURE;
    sf::Sprite asteroid(asteroidt);
    asteroid.move(50,50);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("ressources/arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("ressources/nice_music.ogg"))
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
        window.draw(asteroid);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
