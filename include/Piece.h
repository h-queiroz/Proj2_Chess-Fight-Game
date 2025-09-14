#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>

class Piece {

public:
    enum class Type {
        KING,
        QUEEN,
        BISHOP,
        KNIGHT,
        ROOK,
        PAWN,
    };
    enum class Color {
        WHITE,
        BLACK,
    };

private:
    Piece::Type m_type;
    Piece::Color m_color;

public:
    Piece(Piece::Type type, Piece::Color color);
    Piece::Type getType();
    Piece::Color getColor();
};

#endif // PIECE_H
