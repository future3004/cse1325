#include "tile.h"
#include <string>
#include <iostream>

int Tile::_width = -1;

std::string Tile::_blank;

// contructor 
Tile::Tile(std::string word): _word{word}, _matched{false}{
    if (_width < (int)_word.size()) { 
    _width = _word.size(); 
    _blank = std::string(_width, '-');
  }
}

bool Tile::match(Tile& tile){
    if(_word == tile._word){ _matched = true; tile._matched = true;}
	return _matched;
}

std::string Tile::word(){ return _word; }

bool Tile::matched(){ return _matched; }

std::string Tile::to_string(){
    if(_matched) return _word;
	return _blank;
}

int Tile::width(){return _width;}


