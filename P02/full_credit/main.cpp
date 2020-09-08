#include<iostream>
#include<ctime>

int main(){
 srand(time(NULL));

 std::cout<< rand()%6+1 <<std::endl;
 


 return 0;
}
