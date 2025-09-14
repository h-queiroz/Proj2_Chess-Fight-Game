#include "../include/Piece.h"

Piece::Piece(Piece::Type type, Piece::Color color) : m_type(type), m_color(color) {};

Piece::Type Piece::getType() { return m_type; };

Piece::Color Piece::getColor() { return m_color; };
