#include "board.h"
#include "tile.h"
#include <vector>

std::vector<Tile> Board::_tiles {
{"bang"}, {"beam"}, {"bear"}, {"cafe"}, {"came"},
{"cold"}, {"come"}, {"cool"}, {"date"}, {"diet"},
{"door"}, {"doth"}, {"echo"}, {"exes"}, {"exit"},
{"face"}, {"fame"}, {"feed"}, {"fire"}, {"five"},
{"four"}, {"free"}, {"frog"}, {"from"}, {"game"},
{"goes"}, {"good"}, {"grit"}, {"have"}, {"heal"},
{"hear"}, {"here"}, {"hide"}, {"hole"}, {"home"},
{"hope"}, {"huge"}, {"keep"}, {"kill"}, {"lace"},
{"lame"}, {"leek"}, {"life"}, {"live"}, {"maps"},
{"mass"}, {"mate"}, {"maze"}, {"move"}, {"near"},
{"need"}, {"nine"}, {"once"}, {"quit"}, {"ques"},
{"race"}, {"read"}, {"reed"}, {"reef"}, {"rice"},
{"roof"}, {"sins"}, {"stay"}, {"tame"}, {"teen"},
{"tens"}, {"tide"}, {"tied"}, {"tree"}, {"twin"},
{"zero"}, {"zips"},
};

/*std::vector<Tile> Board::_tiles {
{"bang"}, {"beam"}, {"bear"}, {"cafe"}, {"came"},
{"cold"}, {"come"}, {"cool"}, {"date"}, {"diet"},
};*/

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
