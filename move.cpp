#include "move.h"

move::move(short pieceType, unsigned long long startSquare, unsigned long long endSquare, short takenPiece) {
  this->pieceType = pieceType;
  this->startSquare = startSquare;
  this->endSquare = endSquare;
  this->takenPiece = takenPiece;
}|

short move::getPieceType() {
  return pieceType;
}

short move::getTakenPiece() {
  return takenPiece;
}

unsigned long long getStartSquare() {
  return startSquare;
}

unsigned long long getEndSquare() {
  return endSquare;
}
