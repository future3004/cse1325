#include <iostream>
#include<vector>
#include "tile.h"
#include "board.h"

int main(){

 int userTiles;
 std::cout << "Number of tiles? : ";
 std::cin >> userTiles;
 
 Board b1{userTiles};
 b1.to_string();

 return 0;
}
