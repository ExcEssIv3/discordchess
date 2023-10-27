#include <vector>
#include <array>

#ifndef BOARD_H
#define BOARD_H

struct move {
  // index in bitboard array of piece being moved
  short pieceType;
  // index in bitboard array of piece being taken, -1 if square is empty
  short takenPiece = -1;
  // origin of piece
  unsigned long long startSquare;
  // location piece is moved to
  unsigned long long endSquare;

  bool operator==(const move& lhs, const move& rhs) {
    return lhs.pieceType == rhs.pieceType && lhs.takenPiece == rhs.takenPiece && lhs.startSquare == rhs.startSquare && lhs.endSquare == rhs.endSquare;
  }
}

class board {

  protected:
    // which turn it is, 0 if white and 1 if black
    bool turn;

    // bitboard squareIndex = 8 * rankIndex + fileIndex
    // bitboard list
    // white then black
    // pawn
    // rook
    // knight
    // bishop
    // queen
    // king
    std::array<unsigned long long, 12> bitboard;

    // pressure values for each color
    // pressure represents number of pieces that are attacking for each square by enemy team
    std::array<unsigned short, 64> bpressure;
    std::array<unsigned short, 64> wpressure;

    // current list of legal moves, updated whenever state is changed
    vector<move> legalMoves;


  public:
    // initializes board to starting chess position
    void board();
    // initializes board with fen string
    void board(const char &fen);
    // returns board
    std::array<unsigned long long, 12> getBitboard();
    // returns black pressure
    std::array<unsigned short, 64> getBPressure();
    // returns white pressure
    std::array<unsigned short, 64> getWPressure();
    // returns vector of legal moves
    std::vector<move> getLegalMoves();
    // makes a move given by move parameter, returns exception if move is not in legalMoves
    // updates legalMoves and flips turn bit
    // forced param forces move to be made regardless of if it is legal, default is false
    void move(const move& pos, bool forced = false);

};

#endif
