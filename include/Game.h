#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

// #include "Board.h"

#include <memory>
#include <array>

#include "Piece.h"

class Game {
private:
    bool m_inStrategyStage = true;
    sf::RenderWindow m_mainWindow = sf::RenderWindow(sf::VideoMode({800, 600}), "Kings Duel");
    // Board m_board;
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> m_board = { { nullptr } }; // emptying the 2D Array
    std::unique_ptr<Piece> m_selectedPiece = nullptr;
    sf::Vector2i m_selectedPieceOriginalPos;

public:
    Game();
    void run();
};

#endif // GAME_H
