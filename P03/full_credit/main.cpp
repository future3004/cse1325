#include <iostream>
#include<vector>
#include "tile.h"
#include "board.h"

int main(){
 Tile t1{"RichardMutoniIngabire"};
 std::cout << t1.word() << std::endl;
 std::cout << t1.width() << std::endl;
 
 //std::vector<t1> tiles;
 Board b1{10};
 //std::cout << b1.to_string() << std::endl;

 return 0;
}
