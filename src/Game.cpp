#include "../include/Game.h"
#include "Window/Mouse.hpp"
#include <iostream>

Game::Game() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int desktopWidth = desktopMode.size.x;
    int desktopHeight = desktopMode.size.y;

    int windowWidth = 400;
    int windowHeight = 300;

    m_mainWindow.setPosition({(desktopWidth / 2) - windowWidth, (desktopHeight / 2) - windowHeight}); // Centralizing Window

    // SFML doc recommended to never use the 2 lines below together
    // m_mainWindow.setVerticalSyncEnabled(true); // VSync
    m_mainWindow.setFramerateLimit(60); // Setting to be 60FPS

    // Setting up the board
    m_board[0][1] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::BLACK);
    m_board[1][1] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::BLACK);
    m_board[2][1] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::BLACK);
    m_board[3][1] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::BLACK);
    m_board[4][1] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::BLACK);
    m_board[5][1] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::BLACK);
    m_board[6][1] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::BLACK);
    m_board[7][1] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::BLACK);
    m_board[0][0] = std::make_unique<Piece>(Piece::Type::ROOK, Piece::Color::BLACK);
    m_board[7][0] = std::make_unique<Piece>(Piece::Type::ROOK, Piece::Color::BLACK);
    m_board[1][0] = std::make_unique<Piece>(Piece::Type::KNIGHT, Piece::Color::BLACK);
    m_board[6][0] = std::make_unique<Piece>(Piece::Type::KNIGHT, Piece::Color::BLACK);
    m_board[2][0] = std::make_unique<Piece>(Piece::Type::BISHOP, Piece::Color::BLACK);
    m_board[5][0] = std::make_unique<Piece>(Piece::Type::BISHOP, Piece::Color::BLACK);
    m_board[3][0] = std::make_unique<Piece>(Piece::Type::QUEEN, Piece::Color::BLACK);
    m_board[4][0] = std::make_unique<Piece>(Piece::Type::KING, Piece::Color::BLACK);

    m_board[0][6] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::WHITE);
    m_board[1][6] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::WHITE);
    m_board[2][6] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::WHITE);
    m_board[3][6] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::WHITE);
    m_board[4][6] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::WHITE);
    m_board[5][6] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::WHITE);
    m_board[6][6] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::WHITE);
    m_board[7][6] = std::make_unique<Piece>(Piece::Type::PAWN, Piece::Color::WHITE);
    m_board[0][7] = std::make_unique<Piece>(Piece::Type::ROOK, Piece::Color::WHITE);
    m_board[7][7] = std::make_unique<Piece>(Piece::Type::ROOK, Piece::Color::WHITE);
    m_board[1][7] = std::make_unique<Piece>(Piece::Type::KNIGHT, Piece::Color::WHITE);
    m_board[6][7] = std::make_unique<Piece>(Piece::Type::KNIGHT, Piece::Color::WHITE);
    m_board[2][7] = std::make_unique<Piece>(Piece::Type::BISHOP, Piece::Color::WHITE);
    m_board[5][7] = std::make_unique<Piece>(Piece::Type::BISHOP, Piece::Color::WHITE);
    m_board[3][7] = std::make_unique<Piece>(Piece::Type::QUEEN, Piece::Color::WHITE);
    m_board[4][7] = std::make_unique<Piece>(Piece::Type::KING, Piece::Color::WHITE);
};


// Game Loop;
void Game::run() {
    const int SQUARE_SIZE = 50;
    const float PIECE_SCALE = .15;
    const int SPRITESHEET_DIMENSION = 320;

    int windowXOffset = 200;
    int windowYOffset = 100;

    sf::Texture piecesSpritesheet;
    if (!piecesSpritesheet.loadFromFile("pieces-spritesheet.png"))
        std::cout << "Couldn't manage to find the texture";
    piecesSpritesheet.setSmooth(true);



    while (m_mainWindow.isOpen()) {

        // Handling Events
        while (const std::optional event = m_mainWindow.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                m_mainWindow.close();

            if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    m_mainWindow.close();

            // The code below may look wrong with all the mix of Xs and Ys
            // But one Y represent the window X and Y in the direction that we are used to,
            // while the X and Y from the board are "inverted" in the sense that Y is row and X column
            // So it is confusing, but it is working
            if(const auto* mouseClicked = event->getIf<sf::Event::MouseButtonReleased>())
                if(mouseClicked->button == sf::Mouse::Button::Left)
                    for(int x = 0; x < 8; x++)
                        for(int y = 0; y < 8; y++) {
                            if(m_board[y][x] != nullptr) {
                                int currentPieceMinXPos = (x * SQUARE_SIZE) + windowYOffset;
                                int currentPieceMinYPos = (y * SQUARE_SIZE) + windowXOffset;
                                int currentPieceMaxXPos = ((x * SQUARE_SIZE) + SQUARE_SIZE) + windowYOffset;
                                int currentPieceMaxYPos = ((y * SQUARE_SIZE) + SQUARE_SIZE) + windowXOffset;

                                sf::Vector2i mousePos = mouseClicked->position;

                                if(mousePos.y > currentPieceMinXPos &&  mousePos.y < currentPieceMaxXPos)
                                    if(mousePos.x > currentPieceMinYPos &&  mousePos.x < currentPieceMaxYPos)
                                        std::cout << "Clicked in (" <<  x << ',' << y << ")\n";
                            }
                    }

        }



        m_mainWindow.clear(sf::Color(105, 51, 9));

        sf::Sprite sprite(piecesSpritesheet);
        sf::RectangleShape tilesShape({SQUARE_SIZE, SQUARE_SIZE});
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                // Drawing Board
                if((x + y) % 2 == 0)
                    tilesShape.setFillColor(sf::Color(235, 236, 208));
                else
                    tilesShape.setFillColor(sf::Color(115, 149, 82));

                tilesShape.setPosition({static_cast<float>(y * SQUARE_SIZE) + windowXOffset, static_cast<float>(x * SQUARE_SIZE) + windowYOffset});
                m_mainWindow.draw(tilesShape);

                // Drawing Pieces
                if(m_board[y][x] != nullptr) {
                    sprite.setTextureRect(sf::IntRect({(static_cast<int>(m_board[y][x]->getType()) * SPRITESHEET_DIMENSION), (static_cast<int>(m_board[y][x]->getColor()) * SPRITESHEET_DIMENSION)}, {SPRITESHEET_DIMENSION, SPRITESHEET_DIMENSION}));
                    sprite.setPosition({static_cast<float>(y * SQUARE_SIZE) + windowXOffset, static_cast<float>(x * SQUARE_SIZE) + windowYOffset});
                    sprite.setScale({PIECE_SCALE, PIECE_SCALE}); // I'm not sure why it is so small values but it is

                    m_mainWindow.draw(sprite);
                }
            }
        }

        m_mainWindow.display();
    }
};
