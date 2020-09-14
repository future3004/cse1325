#include "board.h"
#include "tile.h"
#include <vector>
#include<ctime>
#include <algorithm>
#include <cstdlib>

/*std::vector<Tile> Board::_tiles {
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
};*/

/*std::vector<Tile> Board::_tiles {
{"bang"}, {"beam"}, {"bear"}, {"cafe"}, {"came"},
{"cold"}, {"come"}, {"cool"}, {"date"}, {"diet"},
};*/
// //std::cout<< rand()%6+1 <<std::endl; random number inclusive 6
std::vector<std::string> words {
"bang", "beam", "bear", "cafe", "came",
"cold", "come", "cool", "date", "diet",
"door", "doth", "echo", "exes", "exit",
"face", "fame", "feed", "fire", "five",
"four", "free", "frog", "from", "game",
"goes", "good", "grit", "have", "heal",
"hear", "here", "hide", "hole", "home",
"hope", "huge", "keep", "kill", "lace",
"lame", "leek", "life", "live", "maps",
"mass", "mate", "maze", "move", "near",
"need", "nine", "once", "quit", "ques",
"race", "read", "reed", "reef", "rice",
"roof", "sins", "stay", "tame", "teen",
"tens", "tide", "tied", "tree", "twin",
"zero", "zips",
};
//std::rand(time(NULL));

Board::Board(int tiles):tiles{tiles}{
  int random = std::rand()%9+1;
  std::random_shuffle(words.begin(), words.end()); // shuffle list of words
  //for(int i = 0; i < 2; i++){_tiles.push_back};
}

std::string Board::attempt(int tile1, int tile2){
	return "First try";
}

bool Board::solved(){
	return false;
}

std::string Board::to_string(){
  return "Richard KM";
}
