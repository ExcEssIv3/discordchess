#ifndef MOVE_H
#define MOVE_H

class move {
  // index in bitboard array of piece being moved
  short pieceType;
  // index in bitboard array of piece being taken, -1 if square is empty
  short takenPiece;
  // origin of piece
  unsigned long long startSquare;
  // location piece is moved to
  unsigned long long endSquare;

  move(short pieceType, unsigned long long startSquare, unsigned long long endSquare, short takenPiece = -1);

  short getPieceType();
  short getTakenPiece();
  unsigned long long getStartSquare();
  unsigned long long getEndSquare();
// TODO: this needs to be in the class definition in its own CPP file. make a new CPP file
//   bool operator==(const move& rhs) {
//     return this->pieceType == rhs.pieceType && this->takenPiece == rhs.takenPiece && this->startSquare == rhs.startSquare && this->endSquare == rhs.endSquare;
//   }
};

#endif