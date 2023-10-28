#include <array>
#include <vector>
#include "board.h"
#include "move.h"
// using namespace board;

board::board() {
    turn = 0;
    bitboard = {
        0xFF00,
        0x81,
        0x42,
        0x24,
        0x8,
        0x10,
        0xFF000000000000,
        0x8100000000000000,
        0x4200000000000000,
        0x2400000000000000,
        0x800000000000000,
        0x1000000000000000        
    };
    calculatePressure();
    legalMoves = getLegalMoves();
}

// TODO: update to create board using fenstring
board::board(const char &fen) {
    turn = 0;
    bitboard = {
        0xFF00,
        0x81,
        0x42,
        0x24,
        0x8,
        0x10,
        0xFF000000000000,
        0x8100000000000000,
        0x4200000000000000,
        0x2400000000000000,
        0x800000000000000,
        0x1000000000000000        
    };
    calculatePressure();
    legalMoves = getLegalMoves();
}

std::array<unsigned long long, 12> board::getBitboard() {
    return bitboard;
}

std::array<unsigned short, 64> board::getBPressure() {
    return bpressure;
}

std::array<unsigned short, 64> board::getWPressure() {
    return wpressure;
}

std::vector<move> board::getLegalMoves() {
    return legalMoves;
}

// TODO: implement forced functionality after getLegalMoves is implemented
void board::makeMove(const move &pos, bool forced) {
    // subtracting start position and adding end position to piece being moved
    // this functions as moving the piece, as the bit in the start position is changed to zero representing an empty square, and bit in the end position is one, representing a full square
    bitboard[pos.getPieceType()] = bitboard[pos.getPieceType()] - pos.getStartSquare() + pos.getEndSquare();
    // subtracting end position from taken piece if taken piece is not zero, prevents two pieces from being in the same square
    if (pos.getTakenPiece() >= 0) bitboard[pos.getTakenPiece()] -= pos.getEndSquare();
}

void board::calculatePressure() {
    return;
}
