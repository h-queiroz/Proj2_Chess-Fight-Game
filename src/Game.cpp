#include "../include/Game.h"
#include <iostream>

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
    int windowXOffset = 200;
    int windowYOffset = 100;
    m_board[0][0] = std::make_unique<Piece>(Piece::Type::BISHOP, Piece::Color::BLACK);

    sf::Texture piecesSpritesheet;
    if (!piecesSpritesheet.loadFromFile("/home/hector/Development/C++/Proj2_Chess-Fight-Game/pieces-spritesheet.png")) {
        std::cout << "Couldn't manage to find the texture";
    }
    piecesSpritesheet.setSmooth(true);

    while (m_mainWindow.isOpen()) {

        // Handling Events
        while (const std::optional event = m_mainWindow.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                m_mainWindow.close();

            if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    m_mainWindow.close();
        }

        m_mainWindow.clear(sf::Color(105, 51, 9));

        sf::Sprite sprite(piecesSpritesheet);
        sf::RectangleShape shape({50, 50});
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                // Drawing Board
                if((x + y) % 2 == 0)
                    shape.setFillColor(sf::Color(235, 236, 208));
                else
                    shape.setFillColor(sf::Color(115, 149, 82));

                shape.setPosition({static_cast<float>(y * 50) + windowXOffset, static_cast<float>(x * 50) + windowYOffset});
                m_mainWindow.draw(shape);

                // Drawing Pieces
                if(m_board[y][x] != nullptr) {
                    sprite.setTextureRect(sf::IntRect({(static_cast<int>(m_board[y][x]->getType()) * 320), (static_cast<int>(m_board[y][x]->getColor()) * 320)}, {320, 320}));
                    sprite.setPosition({static_cast<float>(y * 50) + windowXOffset, static_cast<float>(x * 50) + windowYOffset});
                    sprite.setScale({0.15f, 0.15f}); // I'm not sure why it is so small values but it is
                    m_mainWindow.draw(sprite);
                }
            }
        }

        m_mainWindow.display();
    }
};
