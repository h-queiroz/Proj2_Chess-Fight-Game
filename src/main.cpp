#include <../include/Game.h>

int main (int argc, char *argv[]) {
    Game game;
    game.run();

    return 0;
    // sprite.setScale({50.f / 320.f, 50.f / 320.f}); // Scale sprite to fit square
}

// void Game::run() {
//     // sf::CircleShape circle(50.f);
//     // circle.setFillColor(sf::Color::Magenta);
//
//     m_board[0][0] = std::make_unique<Piece>(Piece::Type::BISHOP, Piece::Color::BLACK);
//
//     sf::Texture piecesSpritesheet;
//     if (!piecesSpritesheet.loadFromFile("/home/hector/Development/C++/Proj2_Chess-Fight-Game/pieces-spritesheet.png")) {
//         std::cout << "Couldn't manage to find the texture";
//     }
//     piecesSpritesheet.setSmooth(true);
//
//     while (m_mainWindow.isOpen()) {
//
//         // Handling Events
//         while (const std::optional event = m_mainWindow.pollEvent()) {
//             if (event->is<sf::Event::Closed>())
//                 m_mainWindow.close();
//
//             if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
//                 if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
//                     m_mainWindow.close();
//         }
//
//         m_mainWindow.clear(sf::Color(105, 51, 9));
//
//         sf::Sprite sprite(piecesSpritesheet);
//         sf::RectangleShape shape({50, 50});
//
//         // 1. Draw the board first
//         for(int x = 0; x < 8; x++) {
//             for(int y = 0; y < 8; y++) {
//                 if((x + y) % 2 == 0)
//                     shape.setFillColor(sf::Color(235, 236, 208));
//                 else
//                     shape.setFillColor(sf::Color(115, 149, 82));
//
//                 shape.setPosition({static_cast<float>(y * 50), static_cast<float>(x * 50)});
//                 m_mainWindow.draw(shape);
//             }
//         }
//
//         // 2. Draw the pieces on top
//         for(int x = 0; x < 8; x++) {
//             for(int y = 0; y < 8; y++) {
//                 if(m_board[y][x] != nullptr) {
//                     sprite.setTextureRect(sf::IntRect({(static_cast<int>(m_board[y][x]->getType()) * 320), (static_cast<int>(m_board[y][x]->getColor()) * 320)}, {320, 320}));
//                     sprite.setPosition({static_cast<float>(y * 50), static_cast<float>(x * 50)});
//                     sprite.setScale({50.f / 320.f, 50.f / 320.f}); // Scale sprite to fit square
//                     m_mainWindow.draw(sprite);
//                 }
//             }
//         }
//
//         // m_mainWindow.draw(circle);
//         m_mainWindow.display();
//     }
// };
