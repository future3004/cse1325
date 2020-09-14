#include "board.h"
#include "tile.h"

Board::Board(int tiles):tiles{tiles}{}

std::string Board::attempt(int tile1, int tile2){
	return "First try";
}

bool Board::solved(){
	return false;
}

std::string Board::to_string(){
  return "Richard KM";
}
