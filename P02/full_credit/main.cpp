#include<iostream>
#include<ctime>

int main(){
 srand(time(NULL));
 int number_dice, die_faces, number_rolls, random_number;
 int sum = 0;

 //std::cout<< rand()%6+1 <<std::endl;
 std::cout << "Number of dice? : ";
 std::cin >> number_dice;
 std::cout << "Number of faces per die? : ";
 std::cin >> die_faces;
 std::cout << "Number of rolls? : ";
 std::cin >> number_rolls;

 //std::cout <<"Number_dice = " << number_dice << std::endl;
 //std::cout <<"Die_faces = " << die_faces << std::endl;
 //std::cout <<"Number rolls = " << number_rolls << std::endl;
 for(int i = 0; i < number_rolls; i++){
   std::cout << "Roll " << i << ": " << std::endl;
}

for(int j = 0; j < number_dice; j++){
   random_number = rand()% die_faces + 1;
   sum += random_number;
   std::cout << random_number << " ";
   
   
}
   std::cout << "Sum: " << sum << std::endl;
  //std::cout << "Final Sum: " << sum << std::endl;
 
 /*for(int i = 0; i < number_rolls; i++){
   std::cout << "Roll " << i << ": ";
   for(int j = 0; j < number_dice; j++){
   random_number = rand()% die_faces + 1;
   sum += random_number;
   std::cout << random_number + " " 
             << "Sum: " <<  sum << std::endl;
   //std::cout << random_number << " " << std::endl;
  }
}*/
 
 //std::cout << "Final Sum: " << sum << std::endl;


 return 0;
}
