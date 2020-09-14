#include "tile.h"

int Tile::_width = 0;

std::string Tile::_blank = "";

// contructor 
Tile::Tile(std::string word): _word{word}{}

bool Tile::match(Tile& tile){
	return true;
}

std::string Tile::word(){
	return "Apples";
}

bool Tile::matched(){
	return false;
}

std::string Tile::to_string(){
	return _word;
}

int Tile::width(){return _width;}
