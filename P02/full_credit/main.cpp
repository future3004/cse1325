#include<iostream>
#include<ctime>

int main(){
 srand(time(NULL));
 int number_dice, die_faces, number_rolls, random_number;
 int sum = 0, counter = 0;

 //std::cout<< rand()%6+1 <<std::endl;
 std::cout << "Number of dice? : ";
 std::cin >> number_dice;
 std::cout << "Number of faces per die? : ";
 std::cin >> die_faces;
 std::cout << "Number of rolls? : ";
 std::cin >> number_rolls;

/*for(int i = 0; i < number_rolls; i++){
   std::cout << "Roll " << i << ": " << std::endl;
}*/

    while(counter < number_rolls){
        std::cout << "Roll " << counter << ": ";
        for(int j = 0; j < number_dice; j++){
           random_number = rand()% die_faces + 1;
           sum += random_number;
           std::cout << random_number << " "; 
        }
       std::cout << "Sum: " << sum << std::endl;
       counter++;
       sum = 0;
    }

 return 0;
}
