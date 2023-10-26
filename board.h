#ifndef BOARD_H
#define BOARD_H

class board {

protected:
  // black piece bitboards
  unsigned long long bpawns;
  unsigned long long bbishops;
  unsigned long long brooks;
  unsigned long long bknights;
  unsigned long long bqueens;
  unsigned long long bking;

  // white piece bitboards
  unsigned long long wpawns;
  unsigned long long wbishops;
  unsigned long long wrooks;
  unsigned long long wknights;
  unsigned long long wqueens;
  unsigned long long wking;

  // pressure values for each color
  // pressure represents number of pieces that are attacking for each square by enemy team
  unsigned short bpressure[64];
  unsigned short wpressure[64];

public:
  // initializes board to starting chess position
  void initializeBoard();
  // initializes board with fen string
  void initializeBoard(const char &fen);

};

#endif
