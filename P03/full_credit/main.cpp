#include <iostream>
#include<vector>
#include "tile.h"
#include "board.h"

int main(){
 Tile t1{"Richard---MutoniIngabire"};
 std::cout << t1.to_string() << std::endl;
 std::cout << t1.width() << std::endl;
 
 //std::vector<t1> tiles;
 Board b1{10};
 std::cout << b1.to_string() << std::endl;

 return 0;
}
