#include "../include/Game.h"

Game::Game() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int desktopWidth = desktopMode.size.x;
    int desktopHeight = desktopMode.size.y;

    m_mainWindow.setPosition({(desktopWidth / 2) - 400, (desktopHeight / 2) - 300}); // Centralizing Window

    // SFML doc recommended to never use the 2 lines below together
    // m_mainWindow.setVerticalSyncEnabled(true); // VSync
    m_mainWindow.setFramerateLimit(60); // Setting to be 60FPS
};

// Game Loop;
void Game::run() {
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Magenta);

    while (m_mainWindow.isOpen()) {
        while (const std::optional event = m_mainWindow.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                m_mainWindow.close();
        }

        m_mainWindow.clear(sf::Color::Black);
        m_mainWindow.draw(circle);
        m_mainWindow.display();
    }
};
