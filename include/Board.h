#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <memory>
#include <array>

class Board {
private:
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> m_grid = { { nullptr } }; // emptying the 2D Array
};

#endif // BOARD_H
