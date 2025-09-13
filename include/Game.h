#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow m_mainWindow = sf::RenderWindow(sf::VideoMode({800, 600}), "Kings Duel");

public:
    Game();
    void run();

};

#endif // GAME_H
